#!/usr/bin/python3
"""a script that finds a string
in the heap of a running process,
and replaces it
"""

import sys


def print_usage_exit():
    """prints usage error and exits
    """
    print("Usage:{} pid search_string replace_string".format(sys.argv[0]))
    sys.exit(1)


if len(sys.argv) != 4:
    print_usage_exit()

search_string = str(sys.argv[2])
replace_string = str(sys.argv[3])
if search_string == "":
    print_usage_exit()()
try:
    pid = int(sys.argv[1])
    if pid <= 0:
        print_usage_exit()()
except:
    print_usage_exit()()

map_file_str = "/proc/{}/maps".format(pid)
print("[*] maps: {}".format(map_file_str))
mem_file_str = "/proc/{}/mem".format(pid)
print("[*] mem: {}".format(mem_file_str))

try:
    map_file = open(map_file_str, mode='r')
except:
    raise IOError("can not open file {}".format(map_file_str))
    sys.exit(1)
for read_line in map_file:
    phrase = read_line.split(' ')
    memory_address = phrase[0]
    permissions = phrase[1]
    offset = phrase[2]
    inode = phrase[4]
    pathname = phrase[-1][:-1]
    if pathname == "[heap]":
        break
print("[*] Found [heap]:")
print("\tpathname = {}".format(pathname))
print("\taddresses = {}".format(memory_address))
print("\tpermissions = {}".format(permissions))
print("\toffset = {}".format(offset))
print("\tinode = {}".format(inode))
if permissions[0] != 'r' or permissions[1] != 'w':
    print("{} does not have read/write permission".format(pathname))
    map_file.close()
    exit(1)

addresses = memory_address.split("-")
if len(addresses) != 2:
    print("wrong address format")
    map_file.close()
    exit(1)
try:
    head_addr = int(addresses[0], 16)
    tail_addr = int(addresses[1], 16)
    print("[*] Addr start [{}] | end [{}]".format(head_addr, tail_addr))
except ValueError("wrong address value"):
    map_file.close()
    exit(1)

try:
    mem_file = open(mem_file_str, mode='rb+')
except IOError("can not open file {}".format(mem_file_str)):
    map_file.close()
    exit(1)

mem_file.seek(head_addr)
heap = mem_file.read(tail_addr - head_addr)
try:
    h_index = heap.index(bytes(search_string, "ASCII"))
except Exception:
    print("can not find {}".format(search_string))
    map_file.close()
    mem_file.close()
    exit(1)
print("[*] Found '{}' at {}".format(search_string, h_index))

if len(replace_string) > h_index:
    raise ValueError("replace string is too long")
    map_file.close()
    mem_file.close()
    exit(1)
str_position = head_addr + h_index
mem_file.seek(str_position)
print("[*] Writing '{}' at {}".format(replace_string, str_position))
mem_file.write(bytes(replace_string + '\0', "ASCII"))
map_file.close()
mem_file.close()
