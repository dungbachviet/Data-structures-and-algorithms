# DOUBLY LINKED LIST

NGUỒN THAM KHẢO : https://www.geeksforgeeks.org/data-structures/

### 1.	Hàm chèn một node mới vào đầu list
```C++
// Insert a new node at head of doubly linked list
void insertHead(Node **head_addr, int new_data);
```
-	Do trong thao tác có thể cập nhật con trỏ head vì vậy cần phải truyền vào địa chỉ của con trỏ head ban đầu (tức con trỏ cấp 2)

### 2.	Hàm chèn một node mới vào sau một node cho trước
```C++
// Insert a new node after a given node
void insertAfter(Node *prev_node, int new_data);
```
### 3.	Hàm chèn một node mới vào cuối list
```C++
// Insert a new node at last of doubly linked list
void insertLast(Node **head_addr, int new_data);
```
### 4.	Hàm chèn một node mới vào trước một node cho trước
```C++
// Insert a new node before a given node
void insertBefore(Node **head_addr, Node *after_node, int new_data);
```
### 5.	Hàm in danh sách theo 2 chiều : chiều thuận và chiều nghịch
```C++
// Display the doubly linked list
void printList(Node *head);
```
### 6.	Hàm xóa một node trong danh sách liên kết
```C++
// Deletes the given node
void deleteNode(Node **head_addr, Node *deleted_node);
```

-	Do cấu tạo của một danh sách liên kết đôi, một node luôn trỏ tới 2 node phía trước và phía sau nó. Vì vậy, để xóa một node x trong danh sách, ta cần phải thay đổi của 2 node láng giềng (trái và phải) đang trỏ tới nó. Nhưng vấn đề ở đây, đó là : Liệu node trái có tồn tại ? Liệu node phải có tồn tại? Liệu node cần xóa có phải đang là head của danh sách liên kết đó? Cần phải xây dựng một giải thuật tổng quát giúp giải quyết được đồng thời vấn đề này : 

+ Kiểm tra x có phải là head hay không? Nếu có, hay thay đổi 
head = head->next (một cách tổng quát, head mới lúc này có thể bằng NULL hoặc KHÁC NULL)

+ Kiểm tra node bên phải của x có tồn tại? Nếu tồn tại, hãy cho node phải trỏ tới node trái của x (vì x sẽ bị xóa)

 Kiểm tra node bên trái của x có tồn tại? Nếu tồn tại, hãy cho node trái trỏ tới node phải của x (vì x sẽ bị xóa)

+ Giải phóng node x

### 7.	Đảo ngược danh sách liên kết
```C++
// Reverse doubly linked list
void reverse(Node **head_addr);
```
Tư tưởng chính : Bài toán quy về hoán vị các biến con trỏ prev và next của từng Node trong danh sách liên kết đôi. Xét thêm trường hợp khi danh sách liên kết ban đầu có lớn hơn 1 node, khi ấy cần phải cập nhật lại head mới cho list (đã được đảo ngược)

### 8.	Chuyển từ cây nhị phân có thứ tự sang danh sách liên kết đôi vòng có thứ tự
```C++
// Gather leftList and rightList into a new doubly circle list
Node *concatenate(Node *leftList, Node *rightList);

// Convert from Binary Tree to Doubly Circle List
Node *BinaryTreeToCircleList(Node *root);
```
Tư tưởng chính: 
-	Sử dụng kỹ thuật đệ quy tới các cây con trái, cây con phải và gốc để tạo thành các Circle List trái, phải, root-list (list vòng một nút) tương ứng
-	Nối list trái với root-list tạo thành list mới, rồi nối list mới với list phải 
-	Để đảm bảo thứ tự tăng dần trong List thu được : Sử dụng phép duyệt giữa (Inorder) trên cây nhị phân (tức con trái -> root -> con phải)

### 9.	Sử dụng Quick Sort để sắp xếp một danh sách liên kết đôi

```C++
// swap two elements
void swap(int *a, int *b);

// Find last node of doubly linked list
Node *lastNode(Node *head);

// Considers last element as pivot
Node *partition(Node *left, Node *right);

// Wrapper function to call main function of quickSort
void callQuickSort(Node *head);

// Sort linked list using Quick Sort algorithm
void quickSort(Node *left, Node *right);

```
-	Tư tưởng :
+ Chuyển đổi từ Giải thuật Quick Sort cho mảng lấy pivot là phần tử cuối mảng áp dụng cho danh sách liên kết đôi
+ Không tráo đổi node mà tráo đổi các giá trị nằm trong mỗi node
+ Hàm callQuickSort (hàm wrapper) dùng để gọi hàm quickSort chính
-	Độ phức tạp : bằng khi sử dụng Quick Sort cho mảng (Tức O(n^2) cho thời gian tồi nhất, O(nlogn) cho thời gian trung bình)


### 10.	 Sử dụng giải thuật Merge Sort trong sắp xếp danh sách kết nối đôi
```C++
// Split a list into 2 half of list
Node *split(Node *head);

// Merge two orderd lists into one ordered list
Node *merge(Node *first, Node *second);

// Sort list increasingly using Merge Sort algorithm
Node *mergeSort(Node *head);
```
Tư tưởng chính : 
-	Áp dụng giải thuật Merge Sort của mảng áp dụng lên danh sách liên kết đôi, bao gồm các bước chính : Phân tách list thành 2 list (hàm split – Bước chia), thực hiện sắp xếp một cách đệ quy trên từng list con (hàm mergeSort – Bước trị), tổng hợp từ 2 mảng đã được sắp xếp để tạo thành 1 mảng lớn cũng đã được sắp xếp (hàm merge – bước tổng hợp)
-	Hàm split – phân tách list thành 2 nửa list : Sử dụng kỹ thuật con trỏ fast và slow, trong đó : con trỏ fast chạy nhanh gấp 2 lần con trỏ slow, do vậy khi duyệt tới cuối list thì con trỏ slow đang dừng ở giữa mảng -> Con trỏ slow chính là điểm chia thành 2 nửa list
-	Merge : Hàm tổng hợp 2 list đã sắp xếp để tạo thành 1 list cha cũng đã được sắp xếp. Sử dụng tư tưởng đệ quy trong sự tổng hợp -> khá hay
-	MergeSort : Hàm đệ quy gồm 3 bước chính : Chia – Trị - Tổng hợp
