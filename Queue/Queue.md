
# **CẤU TRÚC DỮ LIỆU HÀNG ĐỢI (QUEUE)**

## 1. Giới thiệu chung
- Hàng đợi là một cấu trúc dữ liệu theo nguyên tắc First In First Out (Vào trước Ra trước -  Vào trước Phục vụ trước)
- Ví dụ điển hình : Một dòng người xếp hàng chờ mua một sản phẩm, trong đó người đến trước sẽ được phục vụ trước (ngược lại người đến sau phải chờ và được phục vụ sau)
- Một số thao tác của Hàng đợi : 
  - Enqueue : Nạp một phần tử mới vào cuối (rear-đuôi) hàng đợi. Nếu hàng đợi đầy không thể nạp thêm mới phần tử --> Trạng thái Overflow
  - Dequeue : Xóa một phần tử từ đầu (front) hàng đợi. Nếu hàng đợi rỗng, nghĩa là không thể xóa thêm được bất kỳ phần tử nào --> Trạng thái Underflow
  - Front : Lấy phần tử ở đầu của hàng đợi (phần tử đến đầu tiên - được phục vụ đầu tiên)
  - Rear : Lấy phân tử ở cuối hàng đợi (phần tử đến cuối cùng - được phục vụ cuối cùng)
  
- Ứng dụng của hàng đợi : Bài toán lập lịch cho CPU (trong xử lý các tiến trình nằm trong hàng đợi), Bài toán Lập trình cho ổ đĩa ngoài (yêu cầu phục vụ đọc đĩa từ các tiến trình trong hàng đợi)

## 2. Cài đặt hàng đợi sử dụng Mảng (Array) 

- Ý tưởng : 
  - Tạo một cấu trúc Queue chứa mảng tĩnh, biến front (trỏ tới đầu hàng đợi), rear (tới cuối hàng đợi), Sức chứa (capacity), Số lượng phần tử hiện tại (size)
  - Để tận dụng toàn bộ vùng nhớ trong mảng tĩnh --> Cài đặt hàng đợi dạng vòng (bằng phép modulo - chia lấy dư)
  - Ban đầu, front tại index 0 và rear tại index n-1 (với n là capacity) và size = 0. Thêm 1 phần tử mới : rear = (rear + 1) % n tức bằng 0, lúc này front và rear cùng trỏ tới cùng 1 phần tử, thêm một phần tử mới rear tăng lên 1, front vẫn là 0. Thêm một phần tử mới rear tăng lên 2, front vẫn là 0... Xóa một phần tử front tăng lên 1, rear vẫn bằng 2. Như vậy ta có thể hiểu được quy trình hoạt động của Queue sử dụng mảng tĩnh.

## 3. Cài đặt mảng sử dụng Danh sách liên kết đơn (Linked List)

- Ý tưởng : 
  - Xây dựng một danh sách liên kết đơn chứa 2 con trỏ front và rear lần lượt trỏ tới đầu và cuối của danh sách. Thao tác thêm mới 1 phần tử sẽ thêm vào cuối danh sách (cập nhật lại rear). Thao tác xóa một 1 phần tử sẽ xóa đi phần tử ở đầu danh sách (cập nhật lại front)
  
- File mã nguồn : ImplementQueueUsingLinkedList.cpp

## 4. Hàng đợi ưu tiên (Priority Queue)

- Hàng đợi ưu tiên là một sự mở rộng của hàng đợi (queue) với những thao tác sau :
  - Mỗi phần tử trong danh sách đều được gắn với một độ ưu tiên (priority)
  - Thành phần với độ ưu tiên cao nhất sẽ được lấy ra trước
  - Nếu có 2 phần tử có cùng độ ưu tiên, thì thứ tự phục vụ của chúng sẽ tùy thuộc vào thứ tự bên trong hàng đợi.
  - Các hàm tương ứng : 
    - insert(item, priority) : Chèn 1 phần tử với 1 độ ưu tiên nào đó (Độ phức tạp O(1) với mảng và linked list)
	- getHighestPriority() : Trả lại phần tử có độ ưu tiên cao nhất (Độ phức tạp O(n)với mảng và linked list)
	- deleteHighestPriority() : Xóa phần tử có độ ưu tiên cao nhất (độ phức tạp O(n) với mảng và O(1) với linked list)
	
- Cài đặt hàng đợi ưu tiên được khuyến nghị sử dụng Cấu trúc dữ liệu Heap (Đống) vì thao tác insert và deleteHighestPriority chỉ mất O(log(n)), còn thao tác getHighestPriority chỉ mất O(1)

- Ngoài ra việc cài đặt bằng Fibonacci Heap còn giúp cải thiện hơn nhiều (giúp thao tác insert cũng chỉ mất O(1))

- Do vậy, Hàng đợi ưu tiên sẽ được cài đặt trong bài viết về Heap

## 5. Cấu trúc dữ liệu Deque

- Deque viết tắt của Double Ended Queue là môt phiên bản tổng quát của Cấu trúc dữ liệu Queue mà cho phép các thao tác chèn và xóa ở cả 2 đầu của danh sách

- Các thao tác cơ bản được thực hiện trên deque : 
  - insertFront() : Chèn một phần tử vào đầu danh sách
  - insertLast() : chèn một phần tử vào cuối danh sách
  - deleteFront() : xóa một phần tử ở đầu danh sách
  - deleteLast() : Xóa một phần tử ở cuối của danh sách
  - getFront(), getRear() : Xem phần tử ở đầu và ở cuối danh sách
  - isEmpty(), isFull() : kiểm tra danh sách có rỗng hay có đầy không?
  
- Do sự hỗ trợ từ cả 2 phía nên nó có thể thay thế được cả Stack và Queue
- Java và C++ đều có cấu trúc dữ liệu hỗ trợ cho Dequeue
- Link tham khảo : https://www.geeksforgeeks.org/deque-set-1-introduction-applications/

## 6. Bài toán Sliding Window Maximum (Maximum of all subarrays of size k)

- Bài toán cửa sổ trượt kích thước k, ban đầu cửa sổ chứa k phần tử đầu tiên, chọn ra giá trị lớn nhất trong số k phân tử đó. Sau đó, loại đi phần tử arr[0] và kết nạp phần tử arr[k], rồi lại tìm max trong số k phần tử đó,... Cứ như vậy cho tới khi trượt hết toàn bộ mảng
- Tham khảo : https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

- Ví dụ : arr[] = {1,2,3,1,4,5,2,3,6}, k = 3 thì Output là : 3 3 4 5 5 5 6

- Giải thuật 1 : Một ý tưởng đơn giản nhất có thể nghĩ ra được đó là sử dụng 2 vòng for, vòng for đầu tiên là duyệt từng phần tử, vòng for thứ 2 đi tìm phần tử lớn nhất trong số k phần tử liên tiếp ==> Độ phức tạp O(k*n)

- Giải thuật 2 : Sử dụng cây nhị phân tìm kiếm cân bằng (Self-Balancing Binary Search Tree). Gồm các bước chính sau :
  - Bước 1 : Chọn ra k phần tử đầu tiên và tạo một cây Self-Balancing Binary Search Tree với kích thước k. 
  - Bước 2 : Một vòng lặp for i=0 tới n-k
    - 2a. Chọn ra phần tử lớn nhất từ cây BST và in ra 
	- 2b. Tìm kiếm vị trí của arr[i] và xóa nó khỏi cây BST
	- 2c. Chèn phần tử ar[i+k] vào cây BST
	
  - Giải thuật này với Bước 1 có độ phức tạp O(klog(k)). Bước 2a, 2b, 2c trong 1 lần lặp là O(log(k)) nên trong (n-k+1) lần lặp sẽ là O(log(k)*(n-k+1)) --> Độ phức tạp trên toàn bộ : O(kLog(k) + (n-k+1)*Log(k)) hay có thể viết O(n*Log(k)). Giải thuật này cải tiến hơn chỉ là từ k về thành log(k) (cho bước tìm max, chèn, và xóa sử dụng BST) ==> Sự cải tiến ko thực sự đáng kể
  
- Giải thuật 3 : Sử dụng cấu trúc dữ liệu Deque
  - Ý tưởng : Tạo một Deque với kích thước bằng k mà chỉ lưu trữ những phần tử hữu ích trong cùng một phiên cửa sổ, nghĩa là cửa sổ sẽ chứa các phần tử mà tại đó nó lớn hơn các phần tử khác nằm bên phải nó trong cùng cửa số. Tức trong cửa số đó, phần tử đầu tiên sẽ là phần tử lớn nhất, và phần tử cuối cùng là phần tử nhỏ nhất trong cửa sổ (cửa sổ được sắp xếp một cách giảm dần). Điều quan trọng là cách thức ta cập nhật cửa sổ như thế nào tại từng bước để có thể thu được một cửa sổ như vậy !!! ==> Độ phức tạp O(n) (Một phần tử được đưa vào Deque 1 lần và được lấy ra khỏi Deque 1 lần, tức mất 2 thao tác, mà mỗi thao tác của Deque có thể coi là O(1). Nên độ phức tạp là O(2n) = O(n))
  
  
  


  
  
  
