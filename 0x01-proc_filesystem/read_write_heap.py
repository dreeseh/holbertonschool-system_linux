#!/usr/bin/python3
'''
contains the main method
'''

import sys


def print_usage():
    print('Usage: {} read_write_heap.py pid search_string replace_string'
          .format(sys.argv[0]))
    sys.exit(1)


def main():
    if len(sys.argv) != 4:
        print_usage()

    pid = int(sys.argv[1])
    if pid <= 0:
        print_usage()
    search_string = str(sys.argv[2])
    if search_string == "":
        print_usage()
    replace_string = str(sys.argv[3])
    if search_string == "":
        print_usage()

    map_file_name = '/proc/{}/maps'.format(pid)
    print("[*] maps: {}".format(map_file_name))
    mem_file_name = '/proc/{}/mem'.format(pid)
    print("[*] mem: {}".format(mem_file_name))

    try:
        map_file = open('/proc/{}/maps'.format(pid), 'r')
    except IOError as e:
        print('[ERROR] Cannot open file {}'.format(map_file_name))
        print("        I/O error({}): {}".format(e.errno, e.strerror))
        sys.exit(1)

    for line in map_file:
        split_line = line.split(' ')

        if split_line[-1][:-1] != "[heap]":
            continue
        print("[*] Found [heap]:")

        mem_addr = split_line[0]
        perms = split_line[1]
        offset = split_line[2]
        device = split_line[3]
        inode = split_line[4]
        pathname = split_line[-1][:-1]

        if perms[0] != 'r' or perms[1] != 'w':
            print('{} does not have read/write permission'.format(pathname))
            map_file.close()
            exit(0)

        address = mem_addr.split('-')
        if len(address) != 2:
            print('Wrong address format')
            map_file.close()
            exit(1)

        addr_start = int(address[0], 16)
        addr_end = int(address[1], 16)

        try:
            mem_file = open(mem_file_name, 'rb+')
        except IOError as e:
            print('[ERROR] Cannot open file {}'.format(mem_file_name))
            map_file.close()
            exit(1)

        mem_file.seek(addr_start)
        heap = mem_file.read(addr_end - addr_start)

        try:
            i = heap.index(bytes(search_string, 'ASCII'))
        except Exception:
            print("Can't find '{}'".format(search_string))
            map_file.close()
            mem_file.close()
            exit(0)

        print("[*] Writing '{}' at {:x}"
              .format(replace_string, addr_start + i))
        mem_file.seek(addr_start + i)
        mem_file.write(bytes(replace_string, "ASCII"))

        map_file.close()
        mem_file.close()

        break


if __name__ == '__main__':
    main()
