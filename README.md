# std::vector<bool> Gotchas

This repository demonstrates a common, subtle bug related to the use of `std::vector<bool>` in C++.  `std::vector<bool>` is optimized for space efficiency, but this optimization sacrifices some of the standard container's properties.  This can lead to unexpected behavior and errors if not carefully considered. 

The `bug.cpp` file shows code that produces incorrect results due to the non-standard behavior of `std::vector<bool>` iterators. The `bugSolution.cpp` shows how to fix the code by using a standard container like `std::vector<int>` or `std::vector<char>` if space efficiency is not a critical concern, or a different method if it is.