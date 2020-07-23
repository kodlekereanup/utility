Generic Data Structures and Algorithms Library in C for C
Thread Safe yada yada yada

Vector:
# C++

Initially, when the vector is made, it's size and capacity is 0
std::vector<int> vec; --> (size, cap) = (0, 0)

If constructed with an integer, 
std::vector<int> vec(5) --> (size, cap) = (5, 5)
fills it with zeros
if push_back is used, it doesn't change the initial ones

0 0 0 0 0 1 2 3 4 5 ...

push_back grows the capacity if size == capacity;


# C

Create a variadic make_vector() function that makes a vector from those arguments and returns it.

# TODO

erase
clear
destroy / free
at
swap
assign
emplace
emplace_back
pop_back
pop_front
push_front
push_back
remove
resize
reserve
shrink_to_fit
reverse
front
back
copy

empty?
insert

any
all