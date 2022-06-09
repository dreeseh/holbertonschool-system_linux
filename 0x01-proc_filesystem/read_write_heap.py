#!/usr/bin/python3
"""a script that finds a string
in the heap of a running process,
and replaces it
"""


import sys


def parser():
    """parse and return args.
    """

    pid = int(sys.argv[1])
    string = sys.argv[2]
    new = sys.argv[3]
    if len(new) > len(string):
        raise IndexError

    return pid, string, new


def read_write_file(pid, string, new):
    '''Read mem file and swap the given string
    '''

    maps = "/proc/{:d}/maps".format(pid)
    mem = "/proc/{:d}/mem".format(pid)
    heap = "[heap]"
    perms = {"start": None, "end": None, "perms": None}

    with open(maps, "r") as maps, open(mem, "rb+") as mem:
        for line in maps:
            if heap in line:
                print("[*] Found heap")
                tmp = line.split(" ")
                addr = tmp[0].split("-")
                perms["start"] = int(addr[0], 16)
                perms["end"] = int(addr[1], 16)
                perms["perms"] = tmp[1]
                break

        if perms["perms"][:2] != "rw":
            raise PermissionError

        mem.seek(perms["start"])
        content = mem.read(perms["end"] - perms["start"])
        idx = content.index(bytes(string, "ASCII"))
        print(content)
        print("[*] Found string")
        print("[*] Replacing string")
        mem.seek(perms["start"] + idx)
        mem.write(bytes(new + "\0", "ASCII"))


def main():
    '''Entry point of the script
    '''
    try:
        exit_value = 1
        pid, string, new = parser()
        read_write_file(pid, string, new)
        exit_value = 0

    except Exception as e:
        print(e)
    finally:
        exit(exit_value)


if __name__ == '__main__':
    main()
