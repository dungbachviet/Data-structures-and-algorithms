

# CẤU TRÚC DỮ LIỆU CÂY NHỊ PHÂN (BINARY TREE)

## 1. Giới thiệu về Cây nhị phân (Binary Tree)
https://www.geeksforgeeks.org/binary-tree-set-1-introduction/

- Khác với các cấu trúc dữ liệu tuyến tính như Arrays, Linked List, Stack, Queue... Cây là một cáu trúc dữ liệu phân cấp

- Cấu trúc của cây : Node nằm ở trên đỉnh được gọi là root (rễ) của cây. Những node được nối phía dưới của một node được gọi là con của nó (children). Node được nối phía trên của một node được gọi là cha mẹ (parent) của node đó.

- Tại sao lại sử dụng cấu trúc dữ liệu Cây (tree), bởi vì : 
  - Khi cần thiết phải lưu trữ dữ liệu mang cấu trúc phân cấp (một cách tự nhiên) như : Hệ thống thư mục/file trên máy tính
  - Cây (cụ thể BST - cây nhị phân) cung cấp cách thức tìm kiếm hay truy cập ở mức vừa phải (tức nhanh hơn so với Link List và chậm hơn so với mảng)
  - Cơ chế xóa/chèn trong cây nhanh hơn Mảng và chậm hơn Danh sách liên kết không có thứ tự.
  - Giống như Danh sách liên kết nhưng khác với Mảng ở đặc điểm : Cây không có giới hạn trên cho số node cần lưu trữ.
  
- Ứng dụng chính của cây bao gồm : 
  - Thao tác với những kiểu dữ liệu phân cấp
  - Làm cho thông dễ dàng để tìm kiếm
  - Thao tác với danh sách có thứ tự
  - Áp dụng trong giải thuật định tuyến
  - Cơ chế đưa ra quyết định nhiều giai đoạn (multi-stage decision-making)
  
### - Cây nhị phân :  Là một cây trong đó mỗi thành phần có nhiều nhất 2 node con. Vì mỗi thành phần trong cây nhị phân có duy nhất 2 node nên thông thường chúng ta sẽ gọi chúng tương ứng là : con trái (left child) và con phải (right child).

### - Biểu diễn cây nhị phân : Một cây được biểu diễn bởi một con trỏ tới node gốc (topmost, root) của cây. Nếu cây rỗng, thì giá trị của root là NULL. Một Tree Node sẽ bao gồm các thành phần sau : 
  - Data (dữ liệu)
  - Con trỏ tới con trái
  - Con trỏ tới con phải
  
  
## 2. Cách tính chất liên quan tới cây nhị phân 
https://www.geeksforgeeks.org/binary-tree-set-2-properties/
### 2.1 : Tại mỗi level k, tổng số node lớn nhất tại level đó là : 2^(k-1)
  - Ở đây, level của một node được hiểu là số các node tính từ gốc tới node đó, cụ thể : root có level 1, sau root là level 2, ... cứ như vậy.
  - Ta sẽ chứng minh mệnh đề trên bằng quy nap như sau:
    - Tại root, số lượng nodes = 2^(1-1) = 1 (đúng)
	- Giả sử số node lớn nhất tại một level k nào đó là : 2^(k-1) (*)
	- Như vậy, tại level k+1 thì số node lớn nhất trên level đó là : 2^(k+1-1) = 2^(k). Điều này ta có thể chứng minh như sau : Tại level k, ta có số node lớn nhất là : 2^(k-1), do mỗi node có nhiều nhất 2 node con vì vậy tại level tiếp theo (k+1) thì số node lớn nhất tại level này sẽ là : 2*2^(k-1) = 2^k ==> đpcm
	
### 2.2 : Số lượng node lớn nhất trong cây nhị phân có chiều cao h là 2^h - 1
  - Chiều cao được định nghĩa là : Số node lớn nhất đi đường đi từ gốc tới lá. Nếu cây có 1 node (chỉ có root) thì chiều cao bằng 1 (có một số định nghĩa thì lại mặc định bằng 0, tuy nhiên điều đó ko quan trọng ==> Quan trọng là cách hiểu của ta thôi)
  - Một cây nhị phân có số node lớn nhất khi cây nhị phân đó có số node lớn nhất trên mỗi level của nó. Vì thế, từ 2.1 ta có thể tính được số node lớn nhất bằng : 2^0 + 2^1 + ... + 2^(h-1) = 2^h - 1 (đpcm)
  
### 2.3 : Với một cây nhị phân có N nodes, chiều cao nhỏ nhất có thể có của cây này là : [Log_2(N+1)] (phần nguyên trên của Loga cơ số 2 của N+1)
  - Giải thích : Khi một cây nhị phân đạt trạng thái hoàn hảo thì cây đó sẽ có chiều cao là nhỏ nhất ==> Từ 2.2, ta đã biết rằng một cây với chiều cao h có số node lớn nhất trên cây là 2^h - 1, vì thế : với số node = N thì chiều cao nhỏ nhất thỏa mãn phương trình sau : 2^h - 1 = N <=> 2^h = N + 1 <=> log_2(2^h) = log_2(N+1) <=> h = [log_2(N+1)] (đpcm)
  
  
### 2.4 : Cây nhị phân có L lá thì có ít nhất [Log_2(L)]+1 levels
  - Ta nhận thấy, một cây nhị phân hoàn hảo là cây nhị phân có nhiều lá nhất và ít level nhất (bởi vì nó trải đủ node trên tất cả các level). Vì vậy, với L lá thì có thể tạo ra cây nhị phân với số lượng ít nhất các level là bao nhiêu. Điều này tương đương với việc đây phải là cây nhị phân hoàn hảo, tức theo 2.1 ta có L = 2^(k-1) <=> Log_2(L) = Log_2(2^(k-1)) <=> k = Log_2(L)+1 ) (đpcm, còn chuyện sẽ lấy phần nguyên trên hãy dưới thì chỉ là chi tiết hơn mà thôi)
  
### 2.5. Trong cây nhị phân, số lượng node lá luôn luôn lớn hơn 1 so với các node trong mà có 2 con, tức L = T + 1 (với L là các node lá, còn T là các node trong có 2 con)

## 3. Các kiểu của cây nhị phân
https://www.geeksforgeeks.org/binary-tree-set-3-types-of-binary-tree/
- Cây nhị phân đầy đủ (Full Binary Tree) : Nếu mọi node của nó sẽ có 0 hoặc 2 node con (tức các lá có thể nằm ở các level khác nhau, còn các nút trong nếu có thì luôn luôn có 2 con)
- Cây nhị phân hoàn toàn (Complete Binary Tree) : Là cây nhị phân mà các level đều đầy đủ các node chỉ trừ level cuối, ở level cuối (chứa lá) thì số lá không cần phải đầy đủ, nhưng những lá nếu có thì phải nằm bên trái nhất có thể !!!
- Cây nhị phân hoàn hảo (Perfect Binary Tree) : Là cây nhị phân mà level nào cũng đầy đủ các node (kể cả level lá) ==> Đây chính là cây nhị phân mà có nhiều node nhất và có chiều cao nhỏ nhất
- Cây nhị phân cân bằng : Một cây nhị phân là cân bằng nếu chiều cao của cây là O(log(n)) với n là số node của cây. Ví dụ : Cây AVL luôn duy trì chiều cao là O(log(n)) bằng cách đảm bảo rằng sự khác biệt giữa chiều cao của cây con trái và cây con phải là nhỏ hơn hoặc bằng 1. Cây nhị phân cân bằng giúp thời gian tìm kiếm, chèn hay xóa đều chỉ là O(log(n)).

- Cây nhị phân lãng phí : Là cây nhị phân mà mọi node trong đều chỉ có 1 node con.
	
## 4. Duyệt cây nhị phân
https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
- Khác với các kiểu cấu trúc dữ liệu tuyến tính chỉ có 1 cách duyệt node duy nhất, còn đối với cây có 3 cách duyệt node sau : 
  - Theo thứ tự trước (preorder - Thăm root đầu tiên, sau đó thăm toàn bộ cây con trái, rồi thăm toàn bộ cây con phải) với thủ tục sau :
    - B1 : Thăm root
	- B2 : Duyệt đệ quy cây con trái (gọi hàm preorder cho cây con trái)
	- B3 : Duyệt đệ quy cây con phải (gọi hàm preorder cho cây con phải)
  - Theo thứ tự giữa (inorder - thăm root sau khi thăm toàn bộ cây con trái của nó)
    - B1 : Duyệt đệ quy cây con trái (gọi Inorder cho cây con trái)
	- B2 : Duyệt đệ quy cây con phải (gọi Inorder cho cây con phải)
	- B3 : Thăm root
  - Theo thứ tự sau (postorder - Thăm toàn bộ cây con trái rồi thăm toàn bộ cây con phải, rồi cuối cùng mới thăm root)
    - B1 : Duyệt đệ quy cây con trái (gọi Postorder lên cây con trái)
	- B2 : Duyệt đệ quy lên cây con phải (gọi Postorder lên cây con phải)
	- B3 : Thăm root
	
- Mã nguồn : File TreeTraversal.cpp

## 5. BFS và DFS của cây nhị phân
https://www.geeksforgeeks.org/bfs-vs-dfs-binary-tree/

- Duyệt cây nhị phân ta có 2 phương pháp lớn : Duyệt theo chiều sâu (DFS) và theo chiều rộng (BFS), cụ thể : 
  - Duyệt theo chiều rộng (BFS): Tư tưởng khá giống BFS trong đồ thị - nghĩa là sử dụng Queue để lưu trữ "lan rộng"
  - Duyệt theo chiều sâu (DFS) : chính là bao gồm 3 cách thức duyệt có thứ tự như Inorder, Preorder, Postorder.
  
- Một số bài toán sẽ trình bày trong phần này : 
  - Bài toán duyệt cây nhị phân theo chiều rộng (Level Order Tree Traversal), tác giả sử dụng 2 cách : 
    - Nguồn tham khảo : https://www.geeksforgeeks.org/level-order-tree-traversal/
    - Cách 1 : Cứ đi từng level của cây (bắt đầu từ level 1 - tức gốc) để in ra tất cả các node trong từng level đó ===> Độ phức tạp O(n^2) : đối với cây lãng phí (mỗi node trên một level) thì khi in từng level thì rõ ràng số chi phí ta phải đi tới từng level là : 1 + 2 + 3 + ... + n = O(n^2) (File mã nguồn : LevelOrderTreeTraversal.cpp)
	
	- Cách 2 : Sử dụng Queue (hàng đợi) (sẽ trình bày Queue tự tạo và Queue có sẵn từ ngôn ngữ) (File mã nguồn : LevelOrderTreeTraversalUsingQueue.cpp
	
## 6. Một số hàm tiện ích (File mã nguồn : Utility.cpp)
- Tìm số node của cây nhị phân (Find size of the binary tree) : Để tìm được tổng số node trên cây nhị phân ta có thể sử dụng tư tưởng đệ quy như sau, tổng số nodes trên cây = số node trên cây con trái + Số node trên cây con phải + Node root. Điều này nghĩa là ta sẽ gọi đệ quy để tìm size trên các cây con trái, cây con phải, rồi sau đó tổng hợp lại. Neo đệ quy chính là trường hợp khi node = NULL thì trả về 0 (tức ko có nodes nào trên cây)

- Tìm phần tử lớn nhất và nhỏ nhất trên cây nhị phân : Hãy để ý rằng, phần tử nhất của một cây nhị phân thì hoặc là phần tử root, hoặc sẽ nằm trên cây con trái, hoặc sẽ nằm trên cây con phải ==> Vì thế ta sẽ gọi đệ quy trên các cây con trái và cây con phải ==> Phần tổng hợp sẽ là : so sánh 3 giá trị root, max trên cây con trái, max trên cây con phải ==> Rồi trả về kết quả... Trường hợp Neo là khi gặp một node NULL thì trả về INT_MIN (hoặc ta có thể chọn Neo khác đi đó là : Nếu node đó là lá tức node->left = node->right = NULL thì trả lại giá trị của chính node đó)

- In ra những phần tử trái nhất trên cây nhị phân (Tức node đầu tiên trên mỗi level) : Bài toán này ta cũng có thể áp dụng tư tưởng đệ quy, nhưng cần phải kết hợp một số kỹ thuật khéo léo. Rõ ràng, ta cần phải có những tham số để chỉ ra level của node hiện tại, và một tham số khác cho biết node này có phải là node đầu tiên của level đó không? Việc chỉ ra level của từng node là khá dễ dàng. Nhưng làm sao để biết được một node có phải là node đầu tiên của level ==> Hãy thử suy nghĩ xem : Đối với phép duyệt Preorder (duyệt trước kiểu root - leftTree - rightTree), thì những phần tử đầu tiên của mỗi level (tức trái nhất) luôn được duyệt qua đầu tiên ==> Vì thế ta cần phải có một cơ chế đó là sau khi in ra node trái nhất đó thì cần phải "khóa" level đó lại tức ký hiệu như thế nào đó là những phần tử tiếp theo trong level này ko thể bị in ra nữa ==> Đó chính là vai trò của tham số thứ 3. Trong giải thuật này, tác giả truyền vào 3 tham số : root (rễ của cây), level hiện tại của node, max_level (luôn nhỏ hơn level, nếu max_level>level thì chứng đó phần tử đầu tiên của level này đã được in rồi). Chú ý thêm : biến max_level là một con trỏ luôn trỏ tới một vùng nhớ, tại mọi ngăn xếp của lời gọi hàm ta đều có thể thay đổi vùng nhớ này (vì đã biết địa chỉ rồi) ==> Vai trò của con trỏ này cũng khá giống một biến static (biến tĩnh) trong function !!!

## 7. Tìm đường kính dài nhất của cây nhị phân (Nghĩa là tìm đường dài nhất nối 2 lá của cây nhị phân)
https://www.geeksforgeeks.org/diameter-of-a-binary-tree/

- Phân tích : Hãy để ý rằng, đường kính dài nhất của cây được tạo thành từ 2 height (left height và right height) của một node nào đó trên cây, nhưng quan trọng là node nào đang chứa (left Height + right Height + 1) lớn nhất như vậy ==> Ta cần phải tiến hành phép duyệt một cách đệ quy. Bắt đầu từ root, tìm ra Left Height và Right Heigth của root, như có thể đường kính ko đi qua root, vì thế ta cần phải gọi thêm đệ quy trên các cây con trái và cây con phải (vì có thể đường kính sẽ thuộc một hoặc hai cây con này) ==> Sau đó ta cần phải so sánh 3 giá trị và chọn ra một giá trị lớn nhất trong số : (left height + right height + 1) với Đường kính trên cây con trái và với Đường kính trên cây con phải. Ở đây, neo đệ quy sẽ là : khi node==NULL thì trả về 0 (tức đường kính bằng 0), đồng thời ta cũng cần phải xây dựng thêm hàm tính độ cao của node (đã được xây dựng trong những ví dụ trước rồi) ==> Đây là quá trình đệ quy, nên nó cứ bottom-up từ đáy lên đỉnh cây,... ===> Độ phức tạp O(n^2), tại sao lại vậy : Hãy để ý rằng đây là quá trình duyệt qua toàn bộ node trên cây nhị phân (tức O(n)) nhưng tại mỗi node ta lại thực hiện thao tác tìm chiều cao tại vị trí đó tức mất tối đa là O(n) ==> Vì vậy : độ phức tạp sẽ là O(n^2)

- Ý tưởng cho một giải thuật tối ưu hơn : Vậy làm sao để giảm tử O(n^2) xuống còn O(n) ==> Từ nhược điểm của giải thuật trên, đó là phải mất công tính height tại mỗi node ==> Ta nảy sinh một ý tưởng : Đó là tại sao ta ko tính height cùng với việc tính đường kính (tức thực hiện đồng thời trên cùng 1 lần duyệt). Ý tưởng này là khả quan bởi vì : việc tính height và diameter (đường kính) đều thông qua quá trình đệ quy để đi từ đáy (để gặp neo) rồi lên trở lại đỉnh.
	

	
  
  
  