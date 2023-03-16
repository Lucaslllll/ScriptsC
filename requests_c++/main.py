import ctypes
from ctypes import POINTER, c_char
import pathlib

if __name__ == "__main__":
    # Load the shared library into ctypes
    
    libname = pathlib.Path().absolute() / "libconnect.so"
    c_lib = ctypes.CDLL(libname)
    # c_lib.connects.argtypes = [ctypes.c_char_p,ctypes.c_char_p,ctypes.c_size_t]
    # c_lib.connects.argtypes = [ctypes.c_char_p]
    c_lib.connects.restype = POINTER(c_char)
    answer = c_lib.connects("http://api.yourdiary.top/categories")
    

    
    print(cast(answer, c_char_p).value)