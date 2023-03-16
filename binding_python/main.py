import ctypes
import pathlib

if __name__ == "__main__":
    # Load the shared library into ctypes
    libname = pathlib.Path().absolute() / "libcalc.so"
    c_lib = ctypes.CDLL(libname)
    
    c = input("1 para mult, 2 para div, 3 para soma ou 4 para sub. digite: ")
    number1 = float(input("1º número: "))
    number2 = float(input("2º número: "))

    c_lib.cmult.restype = ctypes.c_float
    c_lib.cdiv.restype = ctypes.c_float
    c_lib.csum.restype = ctypes.c_float
    c_lib.csub.restype = ctypes.c_float

    if c == '1':
        answer = c_lib.cmult(ctypes.c_float(number1), ctypes.c_float(number2))
    elif c == '2':
        answer = c_lib.cdiv(ctypes.c_float(number1), ctypes.c_float(number2))
    elif c == '3':
        answer = c_lib.csum(ctypes.c_float(number1), ctypes.c_float(number2))
    elif c == '4':
        answer = c_lib.csub(ctypes.c_float(number1), ctypes.c_float(number2))
    else:
        answer = "Valor inválido"

    print(f" {answer:.1f}")


