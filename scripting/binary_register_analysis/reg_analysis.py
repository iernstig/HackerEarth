import numpy as np
import sys
from matplotlib import pyplot as plt
import tabulate as tbl
import binascii


def reg_fancy_print():
    print("")
    with open("data/reg_data.txt",mode="r") as f:
        for num, line in enumerate(f):
            print("register: ", num, sep=" ")
            reg_data = int(line, 16)
            print(tbl.tabulate([[31 - i for i in range(32)], list("{:032b}".format(reg_data))], tablefmt="fancy_grid"))


if __name__ == '__main__':
    # reg_4 - 2**20
    #0x04b3
    print(hex(int("0xBC803C", 16) - 2**21))
