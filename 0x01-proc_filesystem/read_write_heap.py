#!/usr/bin/python3
"""
Hack VM
"""
import sys


def main():
    """replace words"""
    if len(sys.argv) != 4:
        print("Usage:read_write_heap.py pid search_string replace_string")
        exit(1)
    pid = sys.argv[1]
    sSearch = sys.argv[2]
    Rstring = sys.argv[3]

    if len(Rstring) > len(sSearch):
        exit(1)

    try:
        maps_file = open("/proc/{}/maps".format(pid), 'r')
    except Exception as e:
        print(e)
        exit(1)

    try:
        mem_file = open("/proc/{}/mem".format(pid), 'r+b', 0)
    except Exception as e:
        maps_file.close()
        print(e)
        exit(1)

    heap_found = False
    for line in maps_file.readlines():
        s_line = line.split()
        if s_line[len(s_line) - 1] == "[heap]":
            heap_found = True
            range_mem = s_line[0].split('-')
            start = int(range_mem[0], 16)
            end = int(range_mem[1], 16)
            mem_file.seek(start)
            s = mem_file.read(end - start)
            index_sSearch = s.find(bytes(sSearch, 'utf-8'))

            if index_sSearch == -1:
                break

            mem_file.seek(start + index_sSearch)
            mem_file.write(bytes(Rstring, 'utf-8') + b'\x00')
            break

    maps_file.close()
    mem_file.close()

    if index_sSearch == -1:
        exit(1)

    if not heap_found:
        exit(1)

    print("replacting string in mem: /proc/{}/mem".format(pid))


if __name__ == "__main__":
    main()
