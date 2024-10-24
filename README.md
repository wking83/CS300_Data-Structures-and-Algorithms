# CS300_Data-Structures-and-Algorithms
When evaluating which data structure to use, we must first complete a pro and con segment for each structure. First, we will look at the Vector Array structure.  Vectors allow for simple implementation. They are usually easy to understand. Reading and splitting lines in a vector is all time dependent on the length of the line but accessing the index is at (O(1)) per line. Some cons are that insertion and deletion can be inefficient if elements are in the middle of the vector. The speed would be (O(n)) due to re-allocation.  Also, if you want to sort based on criteria a vector would not be ideal due to its fixed nature. Memory usage would be based off of the number of courses so the memory usage would be O(n). When printing we will also have to traverse over all elements so we will end up with a O(n) when it comes to printing
Next, we will look at the Binary Search Tree. The BST when it comes to reading and parsing will take on O(n). If the tree is balanced it can take on a O(logn) time with insertion. If the tree is skewed and unbalanced, we can end up with a O(n) transversal performance like vectors. To keep a BST balanced can be more complex to implement and maintain. For printing you will also conduct an in-order transversal when it comes to BST which will lead to O(N). Memory usage is dependent on the number of nodes so that would lead to a O(n) usage. 
Lastly, we have the Hash Table, This also takes on a O(1) read and parsing time. Insertion can be extremely efficient with a O(1) time if no hash collisions. It is possible with many hash collisions for the program to degrade down to a O(n) speed. Memory usage can be a little higher due to overhead and collision resolution, but still at O(n) usage. 

Structure	Insertion	Searching	Total	Memory
Vector	O(1)	O(n)	O(N)	O(N)
BST	O(logn)	O(n)	O(nlogn)	O(N)
Hash	0(1)	O(1)	O(1)	O(N)

In the end I will have to recommend the Hash Table as the most useful candidate for the course management system. The average search and insertion time of O(1) sets it apart from the other structures. At worst it still will be just as last as a vector even with many collisions. These collisions can be mitigated with specific collision techniques. The simplicity of the Hash Table also gives it a major advantage over the binary tree. 