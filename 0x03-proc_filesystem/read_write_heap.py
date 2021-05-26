#!/usr/bin/python3
""" contains the main method
"""
import sys


def main():
    """ a script that finds a string in the heap
    of a running process, and replaces it
    """
    if len(sys.argv) != 4:
        print("Usage: read_write_heap.py pid search_string replace_string")
        exit(1)

    pid = int(sys.argv[1])
    search_string = sys.argv[2]
    write_string = sys.argv[3]

    try:
        file_maps = open("/proc/{}/maps".format(pid), 'r')
    except Exception as e:
        print(e)
        exit(1)

    try:
        memory_file = open("/proc/{}/mem".format(pid), 'r+b', 0)
    except Exception as e:
        print(e)
        exit(1)

    heap_found = False
    for line in file_maps:
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

    file_maps.close()
    memory_file.close()

    if not heap_found:
        print("heap not found")
        exit(1)

    print("now replacing string in memory: /proc/{}/mem".format(pid))

if __name__ == "__main__":
    main()
