### CẤU TRÚC DỮ LIỆU STACK

Link tới nguồn tham khảo : https://www.geeksforgeeks.org/data-structures/

# 1.	Giới thiệu chung về Stack 
-	Hoạt động theo cơ chế : Last In First Out (LIFO) hay First In Last Out (FILO)
-	Các thao tác cơ bản đối với cấu trúc dữ liệu Stack : 
+ Push : Thêm một item vào đỉnh của stack
+ Pop : Lấy item từ đỉnh của stack
+ Peek or Top : Xem đỉnh của stack
+ isEmpty : Stack có đang rỗng không?
+ isFull :  Stack có đang đầy không?

-	Liên tưởng thực tế : Hình ảnh xếp chồng sách, Xếp chồng đĩa (những đĩa được xếp sau những lại được lấy ra và rửa trước)

# 2.	Thiết kế cấu trúc dữ liệu Stack sử dụng mảng 
-	Tư tưởng chính : 
+ Tạo ra một struct Stack chuyên chứa và quản lý stack : gồm 3 thành phần, đó là : capacity (lưu sức chứa tối đa của stack, do sử dụng mảng tĩnh nên cần có sự giới hạn về công suất chứa), top (lưu lại vị trí của top trong stack), con trỏ array (trỏ tới mảng tĩnh chứa dữ liệu)
+ Khi push/pop item cần có những thao tác kiểm tra stack có đang đầy hay đang rỗng (tương ứng)?
-	Mã nguồn chứa bên trong file : StackUsingArray.cpp

# 3.	Thiết kế cấu trúc dữ liệu Stack sử dụng Danh sách liên kết đơn (Linked List)
-	Tư tưởng chính : 
+ Con trỏ head luôn trỏ tới top của Stack
+ Các thao tác push (thêm mới node) hay pop (lấy node ra khỏi stack) đều có thao tác cập nhật lại con trỏ head

-	Mã nguồn chứa bên trong file : StackUsingLinkedList.cpp
# 4.	Bài toán chuyển đổi từ một biểu thức trung tố về hậu tố (Infix To Postfix)

int infixToPostfix(char *expression);
-	Biểu thức trung tố : Toán tử nằm giữa 2 toán hạng, với dạng như : a + b – c * d
-	Biểu thức hậu tố : Toán tử nằm sau hai toán hạng cần tính. Ví dụ : a b + (nghĩa là a + b) hoặc a b c + * (nghĩa là : a * (b+c))

-	Tại sao nên sử dụng biểu thức hậu tố : 
+ Việc tính toán một biểu thức hậu tố sẽ nhanh chóng và đơn giản hơn nhiều so với các biểu thức trung tố vì ta chỉ cần duyệt 1 lần từ trái qua phải trong biểu thức hậu tố để tìm ra được kết quả; trong khi với biểu thức trung tố cần phải xét đến thứ tự ưu tiên của toán tử cũng như tính kết hợp (từ trái sang phải hay từ phải sang trái khi các toán tử được xét là cùng độ ưu tiên), thậm chí còn phức tạp hơn nhiều trong trường hợp có sự đóng góp của nhiều dấu đóng-mở ngoặc trong một biểu thức trung tố,…

-	Chú thích về tính kết hợp (Tức khi các toán tử có cùng độ ưu tiên thì sẽ ưu tiên tính về bên nào trước (trái hay phải?))
+ Tính kết hợp từ trái sang phải bao gồm các nhóm toán tử có cùng độ ưu tiên sau : (+, -), (*, /)
+ Tính kết hợp từ phải sang trái bao gồm các nhóm toán tử có cùng độ ưu tiên sau : (^)

-	Giải thuật : 
+ Từ biểu thức trung tố cho trước, duyệt từ trái qua phải, với mỗi ký tự được gặp : 
+ Nếu nó là một toán hạng, luôn xuất (output) ký tự đó ra
+ Nếu nó là một toán tử, xảy ra 2 khả năng : 
•	Khả năng 1 : Toán tử này có độ ưu tiên cao hơn, hoặc có độ ưu tiên bằng nhưng theo quy tắc kết hợp của toán tử đó là từ phải sang trái so với toán tử nằm ở đỉnh của stack. Hãy đẩy toán tử này vào stack

•	Khả năng 2 : Ngược lại, khi toán tử có độ ưu tiên nhỏ hơn, hoặc bằng nhưng theo quy tắc kết hợp từ trái sang phải so với toán tử nằm ở đỉnh stack. Hãy đẩy toán tử từ stack ra ngoài cho tới khi gặp toán tử đầu tiên có độ ưu tiên cao hơn hoặc bằng nhưng có tính kết hợp từ phải sang trái thì đẩy toán tử đang xét vào stack (quay lại khả năng 1)

+ If gặp ký tự ‘(‘ (mở ngoặc), luôn đầy vào trong stack
+ Nếu gặp ký tự ‘)’ (đóng ngoặc), đưa các toán tử trong stack ra ngoài cho tới khi gặp được ký tự ‘(’ (mở ngoặc)

+ Lặp lại các bước trên cho tới khi toàn bộ biểu thức đều đã được quét 


-	File mã nguồn : InfixToPostfix.cpp


# 5.	Hàm tính giá trị từ một biểu thức hậu tố
int evaluatePostfix(char *postfixExp);

-	Tư tưởng chính : 
+ Duyệt biểu thức hậu tố từ trái qua phải, nếu gặp toán hạng hãy đưa vào trong ngăn xếp, nếu gặp toán tử hãy lấy 2 toán hạng đầu tiên trong ngăn xếp ra rồi tính toán 2 toán hạng đó với toán tử đang xét và đưa kết quả vào ngăn xếp -> Cứ như vậy cho tới khi duyệt hết biểu thức hậu tố, lúc này trong ngăn xếp chỉ còn lại một giá trị và đó chính là kết quả của biểu thức hậu tố !!!

-	File mã nguồn : InfixToPostfix.cpp

# 6.	Hàm đảo ngược một xâu
void reverseUsingStack(char str[]);
void reverse(char str[]);

-	Tư tưởng chính : 
+ Cách 1 : Hàm reverseUsingStack – sử dụng một ngăn xếp để đưa hết các ký tự từ xâu vào, sau đó lấy lần lượt các ký tự trong ngăn xếp ra -> Thu được xâu bị đảo ngược
+ Cách 2 : Hàm reverse – Cách này không cần phải sử dụng thêm một vùng nhớ khác (tức không tạo ra một ngăn xếp như cách 1), ở đây sử dụng việc đảo xâu bằng cách sử dụng kỹ thuật swap nội dung trong các con trỏ tại các vị trí đối xứng trong xâu !!!

-	File mã nguồn : InfixToPostfix.cpp


# 7.	Cài đặt 2 stack trên cùng một mảng tĩnh

-	Tư tưởng chính : 
+ Trong các ví dụ trước, chúng ta đã cùng đi tạo chỉ 1 stack trên 1 mảng (tĩnh). Lúc này bài toán đặt ra, đó là : Cài đặt 2 stack trên cùng 1 mảng tĩnh. Ý tưởng ban đầu có thể đặt ra đó là : chia đôi mảng thành 2 nửa, mỗi nửa sẽ là một stack riêng nhưng cách cài đặt này thật sự không hiệu quả và gây lãng phí trong trường hợp 1 stack đang cạn kiệt vùng nhớ lưu trữ, trong khi stack còn lại chiếm quá nhiều vùng nhớ rảnh rỗi-> Một giải pháp tối ưu hơn được đặt ra, đó là : Cài đặt 2 stack trên 2 phía đối ngược của một mảng cho trước. Với cách này giúp chúng ta tận dụng được vùng nhớ trên cả 2 stack

+ Nói chung, việc sử dụng mảng tĩnh trong thực tế là khó thực hiện bởi kích thước của 1 mảng là không thể biết trước  Hãy cân nhắc sử dụng mảng động (linked list)

-	File cài đặt : TwoStacks.cpp

# 8.	Bài toán kiểm tra tính cân bằng của biểu thức chứa các dấu ngoặc như : [({})]
-	Ý tưởng chính : 
+ Xây dựng một ngăn xếp (sử dụng danh sách liên kết đơn), duyệt từng ký tự trong biểu thức. Nếu gặp dấu ngoặc mở, hãy đưa nó vào ngăn xếp. Nếu gặp dấu ngoặc đóng, hãy lấy 1 ký tự từ trong ngăn xếp rồi kiểm tra đó có phải là một cặp ngoặc hợp lệ; nếu đúng hãy làm tương tự tới hết xâu, còn nếu sai, dừng chương trình và kết luận biểu thức ngoặc đó không cân bằng

-	File mã nguồn : BalancedParentheses.cpp


		
