

# CẤU TRÚC DỮ LIỆU : CÂY NHỊ PHÂN TÌM KIẾM (Binary Search Tree)

### *Nguồn tham khảo :https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/*

## 1. Giới thiệu về cây nhị phân tìm kiếm
- Cây nhị phân tìm kiếm (Binary Search Tree) là một cấu trúc dữ liệu cây nhị phân dạng node mà có những tính chất sau :
  - Cây con trái của một node chỉ chứa những nodes với keys nhỏ hơn so với node đang xét
  - Cây con phải của một node chỉ chứa những nodes với keys lớn  hơn so với node đang xét
  - Cây con trái và cây con phải, chúng phải đều là cây nhị phân tìm kiếm
  - Không có những node nào bị trùng (trùng về keys)
  
- Từ những tính chất trên, cây nhị phân tìm kiếm sẽ cung cấp một thứ tự giữa các keys giúp các thao tác như : tìm kiếm, tìm minimum, tìm maximum được thực hiện rất nhanh (vì nếu cây ko có thứ tự thì ta phải so sánh với tất cả các key trong thao tác tìm kiếm một node ==> Thấy được ưu điểm của "tính có thứ tự" trong cây nhị phân tìm kiếm)

- Một số thao tác cần quan tâm trên Binary Search Tree (BST) 
https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
  - Thao tác tìm kiếm key : Tác giả sử dụng tư tưởng đệ quy để tìm kiếm key trong cây nhị phân. Chúng ta so sánh key với root->key, nếu key thực sự bằng root thì trả lại root, nếu key < root->key thì tìm kiếm một cách đệ quy trên cây con trái (root->left), còn nếu key > root->key thì tìm kiếm một cách đệ quy trên cây con phải (root->right). Ở đây, neo sẽ là khi : node==NULL hoặc node->key==key cần tìm ==> return (trả lại) node đó. Độ phức tạp : O(h) với h là chiều cao của cây (tức cớ O(log(n)), còn nếu là cây nhị phân "lãng phí" (tức mỗi node trên 1 level khác nhau) thì độ phức tạp sẽ là O(n) (trường hợp này xảy ra khi các node của nó tăng dần hoặc giảm dần khi đi từ gốc về lá)
  
  - Chèn một key vào BST : Một điều chắc chắn đó là, một key mới luôn luôn được chèn vào lá bởi vì khi so sánh key cần chèn với từng key trên từng node (đi từ gốc xuống) thì chỉ có 2 trường hợp : key cần chèn lớn hơn hoặc nhỏ hơn ==> Vì vậy nó cứ so sánh và chắc chắn sẽ đi xuống tạo node mới ở lá !!! Ý tưởng cho thao tác chèn, tác giả sử dụng tư tưởng đệ quy khá "khéo léo". Nghĩa là : Trong quá trình so sánh key và chuyển dịch dần xuống phía đáy của cây, chỉ tới khi nào ta tìm ra được một ví trí trống phù hợp thì mới tiến hành tạo node mới và chèn vào vị trí đó (đây chính là trường hợp neo), còn những trường hợp không phải là neo thì xử lỷ ra sao? Ở đây tác giả xử lý bằng cách trả về : chính node hiện tại (với dụng ý : đây không phải là vị trí thích hợp để chèn và vị trí này đã đầy rồi!!!). Độ phức tạp là O(h) với h là chiều cao của cây, ở trường hợp tồi tệ nhất tức các giá trị được chèn vào tạo thành cây nhị phân "lãng phí" (mỗi node trên 1 level) (tức các giá trị chèn vào theo thứ tự tăng dần hoặc giảm dần gây ra tình trạng này)
  
- File mã nguồn : BinarySearchTree.cpp
  
## 2. Thao tác xóa một node trên cây nhị phân 
- Đây là một thao tác khá phức tạp : Đầu tiên ta cần phải nhận định có 3 tình huống có thể xảy ra :
  - Nút cần xóa là nút lá (không có con) ==> Chỉ việc xóa lá đó
  - Nút cần xóa có 1 con (con trái hoặc con phải) ==> Làm thế nào để đảm bảo sau khi xóa con này thì cây nhị phân tìm kiếm vẫn giữ được tính chất của nó ==> Chỉ cần xóa nút cha, rồi thay vị trí của node con duy nhất vào vị trí cha của mình
  - Nút cần xóa có 2 con (con trái và con phải) : Theo cấu trúc cây nhị phân tìm kiếm thì cây con bên phải luôn chứa các node lớn hơn node đang xét, vì vậy để đảm bảo vẫn giữ được tính chất của cây sau khi xóa node này ta cần phải lấy node nhỏ nhất trong cây con phải thay thế cho vị trí node cha bị xóa (bởi vì node nhỏ nhất trong cây con phải cũng sẽ luôn lớn hơn node cha và mọi node trong cây con trái ==> Vì thế sẽ vẫn giữ được tính chất của cây nhị phân tìm kiếm) (Hoặc có một cách khác, ngược lại đó là tìm node lớn nhất trong cây con trái và thay vào vị trí node cha bị xóa)
  
- Cài đặt giải thuật sử dụng tư tưởng đệ quy : Vấn đề lúc này là cần phải cài đặt bằng giải thuật đệ quy, đầu tiên chắc chắn chúng ta phải đi tìm được node cần phải xóa (bằng cách so sánh key), sau khi tìm được chính xác node cần xóa thì hãy xác định xem node cần xóa có bao nhiêu node con. Có một kỹ thuật khá hay mà tác giả sử dụng đó là vấn đề : Theo lời gọi đệ quy để di dần xuống phía đáy rồi tới lúc tìm thấy được node cần phải xóa, ta sẽ tiến hành xóa node này và thay thế bằng một node mới, sau đó sẽ tới giai đoạn giải phóng các ngăn xếp lời gọi hàm, đối với những node không phải bị xóa thì ta cần trả lại node của chính nó (tức không bị thay đổi) ==> Vì vậy, hàm đệ quy này : 
  - Đối với các trường hợp neo như : node=NULL, hoặc tìm thấy node bị xóa thì sẽ trả về node mới thay thế cho node cần xóa
  - Còn đối với các trường hợp không phải neo : thì rõ ràng ta phải trả lại chính node đó (trong giai đoạn giải phóng ngăn xếp lời gọi hàm)

  ===> Hãy ghi nhớ kỹ thuật này !!! 
- Độ phức tạp của giải thuật : O(h) với h là chiều cao của cây nhị phân tìm kiếm (Trường hợp tồi nhất sẽ là O(n) khi mà cây nhị phân ở dạng "lãng phí" hay dạng chéo (tức mỗi node trên một cây))
- File cài đặt : BinarySearchTree.cpp

## 3. Tìm Predecessor và Successor của một node với giá trị key trên cây nhị phân tìm kiếm (Predecessor : là phần tử lớn nhất mà nhỏ hơn node đang tìm kiếm, Successor là phần tử nhỏ nhất mà lớn hơn node đang tìm kiếm). Nếu node có giá trị key không xuất hiện trên cây tìm kiếm thì hãy trả 2 giá trị (Predecessor, Successor) ứng với 2 node của cây nhị phân tạo thành 1 khoảng nhỏ nhất mà key thuộc về khoảng đó
- Phân tích : 
  - Nếu tìm thấy node ứng key được yêu cầu tìm kiếm, lúc này hãy tìm predecessor (chính là phần tử lớn nhất của cây con trái, nghĩa là node phải nhất của cây con trái), và hãy tìm successor (là phần tử nhỏ nhất của cây con phải - nghĩa là phần tử trái nhất của cây con phải)
  
  - Do có thể tồn tại hoặc không tồn tại node ứng với key mà đề bài yêu cầu, vì vậy trong quá trình tìm kiếm ta cần phải tìm ra miền nhỏ nhất mà key chứa trong đó ==> Đối với mỗi node của cây nhị phân đang cần xét : 
    - Nếu mà node này có giá trị lớn hơn key cần tìm ==> Nghĩa là ta cần phải tiếp tục tìm ở cây con trái, nhưng hãy tận dụng giá trị của node đang xét này và lưu nó như successor (vì key của node đó lớn hơn key cần tìm)
	
	- Nếu mà node này nhỏ hơn key cần tìm ==> Ta tiếp tục phải đi tìm node ở chứa key ở cây con phải, đồng thời lưu lại giá trị key của node đang xét này như một giá trị  predecessor(bởi này key của node này nhỏ hơn key cần tìm)
	- Quá trình tìm kiếm sẽ đi qua một loạt các node, và khiến cho predecessor và successor liên tục thay đổi cho tới khi hoặc sẽ tìm thấy key (lúc này predecessor và successor là các số liền trước và liền sau key trong một dãy đã sắp xếp), hoặc sẽ duyệt cho tới đáy của cây (nghĩa là ko tìm thấy predecessor và successor)
	
## 4. Bài toán kiểm tra một Binary Tree có phải là Binary Search Tree (BST) hay không?
https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

- File mã nguồn : CheckBST.cpp
- Phân tích : BST là một cây nhị phân có cấu trúc dạng : đối với một node (đang xét) thì tất cả các node trên cây con trái đều nhỏ hơn node này, đồng thời tất cả các node trên cây con phải đều phải lớn hơn node này. Đồng thời cây con trái và cây con phải cũng đều phải là BST (cây nhị phân tìm kiếm).
- Ý tưởng 1 : Thoạt đầu, chúng ta rất dễ bị mắc sai lầm khi đưa một ý tưởng rằng : chỉ cần kiểm tra con trái và con phải của một node để xét xem chúng có lần lượt nhỏ hơn, lớn hơn node đang xét đó không? Rồi cứ kiểm tra một cách đệ quy trên các cây con trái và cây con phải? ==> Nhưng ý tưởng này là không đúng đắn bởi vì nó chỉ đảm bảo con trái nhỏ hơn node hiện tại và con phải lớn hơn node hiện tại đó, nhưng không đảm bảo một điều rằng : Tất cả con trái đều phải nhỏ hơn node hiện tại, và tất cả con phải đều phải lớn hơn node hiện tại ===> Vì vậy một ý tưởng đệ quy đúng đắn được đưa ra, đó là : 
  - Tại mỗi node, tìm node max của cây con trái (bằng cách so sánh toàn bộ các node trong cây con trái để chọn ra giá trị lớn nhất), sau đó tìm node min của cây con phải (bằng cách so sánh toàn bộ các node trong cây con phải để chọn ra giá trị nhỏ nhất này) ==> Sau đó so sánh ==> Nếu vi phạm điều kiện : max_left < current < min_right thì đó ko phải là BST
  - Với chỉ một node là chưa đủ, ta cần phải đảm bảo tất cả các node đều phải xét điều kiện này ==> Vì thế cần có lời gọi đệ quy trên cây con trái và cây con phải, để các cây con trái và các cây con phải cũng phải đảm bảo là cây BST ===> Ý nghĩa của lời gọi hàm này : Lời gọi hàm là một lời gọi đệ quy giúp duyệt hết tất cả các node trong cây !!!
  - Độ phức tạp : O(n^2) (do tại mỗi node ta đều phải mất thời gian đi tìm min, max trên các cây con phải và cây con trái, tức mất thêm O(n) tại mỗi node)
  - Tên method : isBST_1()
  
- Ý tưởng 2 : Ta hãy nhìn nhận một cách khách quan cho từng node trên cây. Ta hãy xét một node trên cây, giả sử ta luôn đảm bảo rằng tất cả các node ở level phía trên của của node (đang xét) đều đã thỏa mãn điều kiện của cây nhị phân (điều giả sử này là quan trọng). Lúc này ta hãy nhìn nhận thật kỹ vào node đang xét, dấu hiện nào sẽ cho ta biết node đó có đang thỏa mãn hay không? ==> Ta chỉ cần nhìn vào 2 sự rẽ nhánh : 
  - Node này sẽ phải nhỏ hơn node tại sự rẽ nhánh trái gần nhất
  - Node này sẽ phải lớn hơn node tại sự rẽ nhánh phải gần nhất
  ==> Vì vậy, nếu trong quá trình kiểm tra nếu ta chỉ cần lưu trữ được 2 sự rẽ nhánh gần nhất này thì chắc chắn sẽ biết được node hiện tại có đang thỏa mãn tính chất cây nhị phân hay không !!!
  ==> Còn một yếu tố "giả sử" các node trên của node đang xét đều đang thỏa mãn có thể thỏa mãn bằng cách : Ta sẽ duyệt từ root của cây, một cách lần lượt tới các level ở phía dưới ==> Như vậy, nếu các level trên đã thỏa mãn thì một node ở level ngay sát dưới có thể sử dụng 2 sự rẽ nhánh trái và phải gần nhất để kiểm tra tính hợp lệ của node này !!!
  - Cài đặt trên phương thức : isBST_2() trong file mã nguồn checkBST.cpp
  - Độ phức tạp O(n) (do phải duyệt hết node để kiểm tra)
  
- Ý tưởng 3 : Dựa trên ý tưởng 1 tức cũng dựa trên 2 lần rẽ nhánh trái, phải gần nhất. Nhưng ở trong phương thức này, ko lưu giá trị của node tại 2 lần rẽ nhánh đó mà sẽ lưu chính đối tượng node tại 2 lần rẽ nhánh gần nhất này. Phương thức cài đạt : isBST_3() trong file mã nguồn checkBST.cpp. Độ phức tạp O(n)

- Ý tưởng 4 : Sử dụng tư tưởng cách phép duyệt giữa (Inorder Traversal)
  - Khi duyệt theo Inorder thì ta sẽ thu được 1 dãy tăng dần ==> Vì vậy hãy cứ duyệt trước thu được một dãy, rồi sau đó kiểm tra dãy này xem có tăng dần hay ko? Nếu không tăng dần thì nó cây nhị phân ko phải là BST. Nếu xét một cách chi li thì rõ ràng giải thuật này sẽ mất O(2*n) tức phải mất 2 lần duyệt : 1 lần duyệt theo Inorder, còn một lần duyệt để kiểm tra có phải dãy tăng (ở lần duyệt thứ 2 này ta cần phải có thêm một vùng nhớ để kiểm tra tính tăng của dãy, thực tế đối với các thiết bị nhỏ gọn việc tăng vùng nhớ sẽ hạn chế khả năng của nó). Vì thế ta mới tự hỏi rằng : Tại sao chúng ta không thử lồng ghép 2 bước này trong một. 
  - Ý tưởng của việc lồng ghép này, đó là : Khi duyệt theo Inorder sẽ duyệt các phần tử theo thứ tự tăng dần, vì vậy ta chỉ cần xây dựng thêm 1 biến tĩnh previous tức phần tử liền trước đó, rồi so sánh phần này hiện tại với phần tử liền trước này, nếu phần tử hiện tại nhỏ hơn phần tử liền trước thì chứng tỏ cây nhị phân không phải là BST, và ngược lại, rồi ta lại tiếp tục cập nhật lại previous mới hiện tại (nếu bước kiểm tra trước là thỏa mãn)... Cứ như vậy cho tới khi :
    - Phát hiện cây bị vi phạm tính chất BST
	- Hoặc duyệt hết cây mà ko tìm thấy vi phạm nào cả 
  
  
  
 
  
  
  