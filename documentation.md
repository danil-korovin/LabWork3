# Circular List
The circ_list is a list with bidirectional iterators, where the last element points back to the first element.

### Constructors:
1. Default Constructor: O(1) - Initializes an empty list .
```
circ_list()
```
2. Constructor with initializer list: O(n) - Constructs the list from an std::initializer_list.
```
circ_list(std::initializer_list<T> init_list)
```
3. Copy constructor: O(n) - Creates a copy of circ_list.
```
circ_list(const circ_list& other)
```
4. Move constructor: O(1) - Transfers head, lsize to new list.
```
circ_list(circ_list&& other)
```
5. Destructor: O(n) - Clears the list.
```
~circ_list()
```

### Assignment Operators:
1. Copy Assignment: O(n) - Cleare list and copying elements from other.
```
operator=(const circ_list& other)
```
2. Move Assignment: O(1) - Transferring the data from one list to another.
```
operator=(circ_list&& other)
```

### Iterators:
1. *it Dereference operator: O(1) - Returns a reference to the data.
2. ->: O(1) - Returns a pointer to the data element.
3. begin(): O(1) - Returns an iterator head.
4. end(): O(1) - Returns null.
5. ++it Prefix Increment operators: O(1) - Moves the iterator to the next element.
6. it++ Postfix Increment operators: O(1) - Moves the iterator to the next element.
7. --it Prefix Decrement operators: O(1) - Moves the iterator to the previous element.
8. it-- Postfix Decrement operators: O(1) - Moves the iterator to the previous element.
9. == Equality : O(1) - Compares two iterators.
10. != Inequality: O(1) - Compares two iterators.

### Basic functions:
1. empty(): O(1) - Checks if the list is empty.
2. size(): O(1) - Returns the number of elements.
3. front(): O(1) - Returns a reference to the first element.
4. back(): O(1) - Returns a reference to the last element.

### Modifiers:
1. push_back O(1) - Adds an element to the end.
```
push_back(const T& value):
```
2. push_back O(1) - Moves add an element to the end.
```
push_back(T&& value)
```
3. push_front O(1) - Adds an element to the beginning.
```
push_front(const T& value) 
```
4. push_front O(1) - Moves add an element to the beginning.
```
push_front(T&& value)
```
5. pop_back O(1) - Removes the last element from the list.
```
pop_back()
```
6. pop_front O(1) - Removes the first element from the list.
```
pop_front() 
```
7. clear O(n) - Removes all elements from the list.
```
clear(): 
```
8. erase O(1) - Removes the element at the position of iterator.
```
erase(iterator pos)
```
9. insert(): O(1) - Inserts an element before the position of iterator.
```
insert(iterator pos, const T& value)
```
10. insert(): O(1) - Move inserts an element before the position of iterator.
```
insert(iterator pos, T&& value)
```

### Functions:
1. find(): O(n) - Searches for a value and returns an iterator.
```
find(const T& value)
```
2. copy(): O(n) - Copies all elements.
```
copy(const circ_list& other)
```
3. reverse_copy(): O(n) - Creates a reversed copy.
```
reverse_copy(const circ_list& other)
```
4. == : O(n) - Check for equality.
```
operator==(const circ_list& other)
```
5. != : O(n) - Check for inequality.
```
operator!=(const circ_list& other)
```
