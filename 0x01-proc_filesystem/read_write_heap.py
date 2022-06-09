#!/usr/bin/python3
'''
contains the main method
'''

import sys


def print_usage_and_exit():
    """
    module for printing usage
    """
    print('Usage: {} pid search write'.format(sys.argv[0]))
    sys.exit(1)

def main():
    if len(sys.argv) != 4:
        print_usage_and_exit()

    pid = int(sys.argv[1])
    if pid <= 0:
        print_usage_and_exit()

    search_string = str(sys.argv[2])
    write_string = str(sys.argv[3])
    if len(write_string) > len(search_string):
        raise IndexError

    map_file_name = '/proc/{}/maps'.format(pid)
    mem_file_name = '/proc/{}/mem'.format(pid)

    try:
        map_file = open("/proc/{}/maps".format(pid), 'r')
    except Exception as e:
            print(e)
            sys.exit(1)

    try:
        memory_file = open("/proc/{}/mem".format(pid), 'r+b', 0)
    except Exception as e:
        print(e)
        sys.exit(1)

    heap_found = False
    for line in map_file:
        s_line = line.split(' ')
        if "heap" in line:
            heap_found = True
            print("found HEAP")

            memory_range = s_line[0].split('-')
            memory_start = int(memory_range[0], 16)
            memory_end = int(memory_range[1], 16)
            memory_file.seek(memory_start)
            memory_search = memory_file.read(memory_end - memory_start)
            index_search = memory_search.find(bytes(search_string, 'ASCII'))

            if index_search == -1:
                print("break one")
                break

            memory_file.seek(memory_start + index_search)
            memory_file.write(bytes(write_string, "ASCII"))
            print("write memory break")
            break

    map_file.close()
    memory_file.close()

    if not heap_found:
        print("heap not found")
        sys.exit(1)

    print("now replacing string in memory: /proc/{}/mem".format(pid))

if __name__ == '__main__':
    main()