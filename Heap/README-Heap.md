
# CẤU TRÚC DỮ LIỆU : HEAP (ĐỐNG)

*Nguồn tham khảo : https://www.geeksforgeeks.org/data-structures/*

## 1. Tìm hiểu về Đống nhị phân (Binary Heap)
- Đống nhị phân là một cây nhị phân với những thuộc tính (tính chất) sau : 
  - Nó là một cây nhị phân hoàn toàn (nghĩa là mọi level của nó đều chứa đầy đủ các node ngoại trừ level cuối cùng, các node lá trong level cuối cùng phải được xếp trái nhất có thể). Từ tính chất của đống nhị phân nên nó phù hợp để được lưu trữ dưới dạng Mảng (Array).
  
  - Đống nhị phân có thể là Đống Min hoặc Đống Max. Đối với Đống Min (Min Heap), root sẽ chứa giá trị nhỏ nhất, một cách đệ quy tính chất này phải đúng trên từng toàn bộ các cây con của Đống Min (tức mọi node cha đều phải nhỏ hơn các node con của nó). Tương tự đối với Đống Max
  
  - Ví dụ về đống Min :
  
    ![Đống Min](https://github.com/dungbachviet/Data-structures-and-algorithms/blob/master/Heap/min-heap.PNG)
	
- Cách biểu diễn Đống nhị phân : Đống nhị phân là một cây nhị phân hoàn toàn, một đống nhị phân thường được biểu diễn như một mảng (Array)
  - Root nằm tại phần tử đầu tien của mảng, tức Arr[0]
  - Tại một vị trí index i của mảng, ta có thể tìm ra vị trí của node cha, con trái và con phải của node này trên mảng như sau : 
    - Arr[(i-1)/2] : Trả lại node cha
	- Arr[2*i + 1] : Trả lại con trái
	- Arr[2*i + 2] : Trả lại con phải
	
- Phương pháp duyệt Đống nhị phân để nó trả về thứ tự giống như trong một mảng là : Level Order (Duyệt theo từng level từ level 0, 1,... tới level cuối cùng tức level lá. Phương pháp duyệt này thực chất là duyệt theo chiều rộng BFS như đã đề cập trong bài về Cây nhị phân (Binary Tree) trước đó)

- Ứng dụng của Đống (Heap) : 
  - Sắp xếp một dãy số sử dụng kỹ thuật Heap Sort (bằng Đống nhị phân - Binary Heap) trong thời gian O(n*log(n))
  - Hàng đợi ưu tiên : Là một sự mở rộng của hàng đợi nhưng quan tâm tới độ ưu tiên của từng node trong các thao tác thêm và xóa node ra khỏi hàng đợi(Node có độ ưu tiên cao sẽ được lấy ra trước các node có độ ưu tiên thấp hơn; trường hợp nhiều node có cùng độ ưu tiên thì việc lấy ra node tiếp theo sẽ dựa vào thứ tự của các node trong hàng đợi. Phần này đã được bàn luận trong Cấu trúc dữ liệu Hàng Đợi - Queue) ==> Cách thức cài đặt Hàng đợi ưu tiên hiệu quả sử dụng Đống nhị phân, bởi vì cấu trúc dữ liệu Đống nhị phân cho phép các thao tác như Chèn, Xóa, Lấy node lớn nhất (trong Min Heap), Giảm key của Node chỉ mất thời gian O(log(n)) (tức bằng độ sâu của cây). Một số biến thể của Binary Heap đó là : Binomoial Heap, Fibonacci Heap.
  - Ứng dụng trong các giải thuật Đồ thị (Graph Algorithms) : Sử dụng Hàng đợi ưu tiên sử dụng Đống nhị phân trong các bài toán đồ thị như Dijstra's Shortest Path, Prim's Minimum Spanning Tree.
  - Một số bài toán có thể giải quyết khá hiệu quả nhờ sử dụng Heap như : K'th Largest Element in an array (Tìm kiếm k thành phần lớn nhất trong một mảng), Sort an almost sorted array(sắp xếp một mảng mà gần như đã đúng thứ tự), Merge K sorted arrays (Hợp nhất K mảng đã được sắp xếp thành 1 mảng được sắp xếp)
  
## 2. Cài đặt Đống nhị phân (Implementation of Binary Heap)
- Thực hiện cài đặt cho Min Heap (còn Max Heap sẽ được cài đặt một cách tương tự)
- Một số thao tác cần phải cài đặt với Min Heap : 
  - getMini() : Trả lại root của Min Heap (giá trị nhỏ nhất). Độ phức tạp của thao tác này là O(1) do root nằm ở phần tử đầu tiên trong mảng
  
  - extractMin() : Xóa phần tử nhỏ nhất từ Min Heap (tức xóa root), sau khi xóa root phải tiến hành bảo trì lại cho Min Heap. Ý tưởng : Thay thế phần tử root bằng một phần tử ở cuối mảng, rồi giảm đi kích thước size của Min Heap. Lúc này, có thể root mới đang vi phạm tính chất của một đống Min, nhưng các cây con trái và con phải của nó vẫn thỏa mãn được tính chất này. Vì vậy, ta chỉ việc so sánh root với con trái và con phải, rồi hoán đổi chúng một cách phù hợp,... việc hoán đổi sẽ dừng lại cho tới khi gặp một node đầu tiên mà nhỏ hơn cả 2 con trái-phải của nó (công việc bảo trì này ta thường gọi là heapify cho Đống Min/Max) ==> Vì thế độ phức tạp cho tác tác này là O(log(n))
  
  - decreaseKey() : Giảm giá trị cho của một node. Việc giảm giá trị của một node có thể dẫn tới sự vi phạm tính chất của Min Heap, khi giá trị sau khi được giảm của node đó nhỏ hơn node cha của nó ==> Vì vậy ta cần phải truy dẫn dần lên phía root, và thực hoán vị node (bị giảm giá trị) với node cha của nó,... cứ như vậy cho tới khi gặp node cha lớn hơn ==> Độ phức tạp của thao tác này là : O(log(n)) (Nói thêm : Mục đích của thao tác giảm giá trị của một node là cần thiết trong các bài toán thực tế về Hàng đợi ưu tiên khi mức độ ưu tiên của một node bị giảm dần theo thời gian)
  
  - insert() : Chèn một node mới vào Min Heap. Với ý tưởng, chèn node mới vào cuối mảng (tức node lá cuối cùng cây Min Heap), nếu node mới lớn hơn node cha có nghĩa là tính chất của cây vẫn được duy trì, còn ngược lại nếu node mới nhỏ hơn node cha, ta tiến hành hoán vị 2 node này trong mảng,... cứ so sánh như vậy theo hướng gần hơn về gốc, cho tới khi gặp một node cha nhỏ hơn mình. Độ phức tạp của thao tác này là O(log(n))
  
  - delete() : Thực hiện xóa một node. Đây là thao tác phức tạp hơn cả, vì nó đụng chạm tới khá nhiều tình huống : node bị xóa là lá, là node trong có 1 con, 2 con. Một ý tưởng rất hay mà tác giả đề xuất đó chính là : Gán lại giá trị cho node cần xóa là INT_MIN, rồi maintain tính chất của cây Min Heap nhằm đẩy node này lên trở thành root mới, rồi sau đó thực hiện xóa root nhờ thao tác extractMin() (như đã nói : thao tác này sẽ gán phần tử cuối cùng của mảng cho root, giảm size của đống, rồi heapify lại Min Heap đó). Thao tác này có độ phức tạp : O(log(n)) (tính một cách chi li hơn thì là : 2*O(log(n)))
  
## 3. Tại sao Đống Nhị Phân (Binary Heap) lại được ưu tiên hơn so với Cây Nhị Phân Tìm Kiếm (Binary Search Tree) cho Hàng Đợi Ưu Tiên (Priority Queue)

- Một Hàng đợi ưu tiên được đặc trưng bởi các thao tác chính sau : 
  - Lấy node lớn nhất hoặc nhỏ nhất (root node)
  - Chèn vào một node
  - Xóa thành phần (node) có độ ưu tiên lớn nhất hoặc nhỏ nhất
  - Giảm giá trị của key trên node

- Một Đống Nhị Phân hỗ trợ các thao tác trên với độ phức tạp về thời gian tìm kiếm như sau : 
  - O(1) : (vì node lớn nhất hoặc nhỏ nhất sẽ nằm ở root tương ứng trong Max Heap và Min Heap)
  - O(log(n)) : Đi từ gốc và so sánh key cần chèn với root, con trái, con phải để có thể định hướng đúng cho vị trí cần chèn vào
  - O(log(n)) : Xóa root và thao tác bảo trì (maintain tính chất cho cây) bằng cách sử dụng lá cuối cùng thay thế root rồi tiến hành heapify
  - O(log(n)) : Giảm key của một node. Sau khi giảm key ta cần phải di chuyển theo hướng tới gốc (root) để hoán vị node hiện tại với các node xuất hiện trên đường đi tới gốc này.
  
- Cây nhị phân tìm kiếm cân bằng (Self Balancing Binary Search Tree) như AVL Tree, Red-Black Tree, etc... có thể hỗ trợ các thao tác trên với cùng độ phức tạp thời gian
  - Tìm kiếm minimum hoặc maximum không thực sự mất O(1) nhưng ta có thể dễ dàng cài đặt trong thời gian O(1) bằng việc duy trì sử dụng một con trỏ tới minimum và maximum, sẽ update các con trỏ này khi gặp các thao tác chèn hoặc xóa.
  - Chèn một thành phần với độ phức tạp O(log(n)) vì chỉ cần so sánh từ root xuống dưới đáy để tìm ra vị trí thích hợp để chèn
  - Xóa thành phần lớn nhất và nhỏ nhất : Vì thành phần lớn nhất và nhỏ nhất nằm một cách tương ứng trên phía phải nhất của cây con phải, và phía trái nhất của cây con trái, mà các thao tác tới được các vị trí này đòi hỏi thời gian O(log(n))
  - Giảm key của một node cũng mất thời gian O(log(n)). Thao tác giảm key được thực hiện trong cây nhị phân tìm kiếm như sau : Tiến hành xóa node với key cũ, rồi Chèn một node mới với key mới. Thời gian tìm key cũ tốn O(logn), thời gian chèn key mới tốn O(logn). Như vậy tổng thời gian là O(logn)
  
- Tại sao Đống Nhị Phân lại phù hợp đối với Hàng Đợi Ưu Tiên : 
  - Vì Đống Nhị Phân được cài đặt sử dụng mảng, do đó có sự định vị tham chiếu tốt hơn và các thao tác của nó thân thiện hơn với bộ nhớ cache.
  - Chúng ta có thể xây dựng được một Đống Nhị Phân với thời gian O(n) (như biến thể Fibonacci Heap vì thao tác chèn 1 node mới chỉ tốn O(1) nên khi xây dựng một đống thì sẽ tốn n*O(1)=O(n)). Còn Cây nhị phân tìm kiếm cân bằng phải mất thời gian O(nlog(n)) vì thời gian chèn một node mới của nó mất O(log(n)) thời gian.
  - Đống Nhị Phân không yêu cầu thêm không gian lưu trữ con trỏ.
  - Đống Nhị Phân dễ dàng cài đặt hơn.
  - Có một vài biến thể của Binary Heap như Fibonacci Heap mà có thể hỗ trợ các thao tác chèn, giảm key với thời gian chỉ là O_TB(1) (Theta - O Trung bình)

- Nhưng BST lại có những đặc trưng tốt hơn Heap ở những khía cạnh khác (cho những bài toán khác) như : 
  - Tìm kiếm một thành phần trong Cây nhị phân tìm kiếm (Self-balancing BST) chỉ mất O(logn), trong khi sẽ phải mất tới O(n) với Binary Heap (bởi vì con trái và con phải của một node trong Binary Heap không cho biết được thông tin số nào lớn hơn, vì thế thao tác tìm kiếm cứ phải duyệt hết để tìm kiếm node)
  - In tất cả các thành phần theo thứ tự tăng dần mất O(n) với BST, trong khi với BH (Binary Heap) sẽ mất O(n(logn)) (tức cứ phải lấy root rồi xóa đi, mỗi thao tác như vậy mất O(logn), cả thảy với n thành phần sẽ mất O(nlog(n))
  - Tìm Floor và Ceil của một key (tức tương ứng là node lớn nhất nhưng nhỏ hơn key và node nhỏ nhất nhưng lớn hơn key) ==> Chỉ mất thời gian O(Logn) với BST vì nó chỉ cần duyệt từ gốc để tìm (do con trái và con phải là có phân biệt lớn-nhỏ nên rất dễ dàng tìm kiếm, trong khi đó Heap lại tỏ ra yếu kém hơn về các thao tác liên quan tới thứ tự)
  - Bài toán tìm thành phần lớn-nhỏ thứ K : tồn thời gian O(logn) bằng việc sử dụng Augmenting Tree (tức node sẽ có thêm một trường mới nhằm hỗ trợ cho bài toán này)
  
## 4. Bài toán tìm k thành phần lớn nhất trong một mảng
- Ý tưởng 1 : Sử dụng giải thuật Bubble Sort k lần để tìm ra k thành phần lớn nhất. Độ phức tạp O(k*n)
- Ý tưởng 2 : Sử dụng một mảng trung gian để lưu k thành phần lớn nhất của mảng. Giải thuật này gồm các bước chính như sau : 
  - Bước 1 : Lưu trữ k thành phần đầu tiên từ mảng ban đầu vào mảng tạm thời temp[]
  - Bước 2 : Tìm thành phần nhỏ nhất trong temp[], gán giá trị này bằng biến min
  - Bước 3 : Với mỗi thành phần từ mảng gốc arr[k] tới arr[n-1], ta lần lượt so sánh nó với min của mảng tạm thời temp[]
    - Nếu phần tử đang xét > min, xóa min từ mảng tạm thời, đồng thời chèn phần tử đang xét vào mảng tạm thời đó
	- Cập nhật lại min của mảng tạm thời temp[]
  - Độ phức tạp : O((n-k)*k) vì do phải duyệt n-k phần tử, đồng thời với từng lần duyệt này phải duyệt qua k phần tử trong mảng tạm thời để tìm ra phần tử nhỏ nhất.
  
- Ý tưởng 3 : Sử dụng sắp xếp. Sử dụng một giải thuật sắp xếp nhanh nhất như Quick Sort để sắp xếp mảng với thời gian O(n*log(n)). Mảng sau khi được sắp xếp xong, ta tiến hành in ra k thành phần đầu tiên trong mảng này (tốn O(k)) ==> Như vậy, độ phức tạp thời gian tổng cộng là : O(nlogn + k)

- Ý tưởng 4 : Sử dụng Max Heap. Xây dụng một đống Max Heap với thời gian O(n) (với các thao tác chèn n phần tử vào Max Heap, với mỗi thao tác chèn tốn O(1) trong trường hợp với Fibonacci Heap nên thời gian xây dựng Max Heap là O(n), còn đối với kiểu chèn bình thường sẽ tốn O(logn) nên tổng thời gian chèn sẽ là O(nlogn)). Sau khi xây dựng xong Max Heap, ta sẽ thực hiện thao tác Extract Max (tức lấy root) k lần để tìm ra k thành phần lớn nhất (mỗi thao tác Extract Max tốn O(logn), lấy k lần Root sẽ tiêu tốn O(k*logn))

- Ý tưởng 5 : Được cải tiến từ ý tưởng số 2. Nghĩa là thay vì phải sử dụng Mảng tạm thời chứa k thành phần lớn nhất, ta sẽ sử dụng một min-heap thay thế. Do sử dụng Min Heap nên thao tác tìm min của mảng tạm thời sẽ giảm từ O(k) (duyệt cả k phần tử) xuống còn O(logk) (tìm min nhờ sử dụng cây Min Heap)

##5. Bài toán Hợp nhất k mảng (mỗi mảng có n phần tử) đã được sắp xếp thành một mảng được sắp xếp (gồm n*k phần tử)
- Ý tưởng 1 : Sao chép toàn bộ các thành phần trong k mảng vào 1 mảng chứa n*k phần tử. Rồi tiến hành sắp xếp sử dụng Quick Sort với O_TB(nlogn) hoặc dùng Merge Sort với O(nlogn)

- Ý tưởng 2 : Sử dụng Min Heap. Ý tưởng này có vẻ được cải tiến từ giải thuật Merge Sort cho k mảng đã được sắp xếp. Đối với Merge Sort ở thao tác Merge, ta thực hiện so sánh k phần tử ngoài cùng của mỗi mảng và chọn ra phần tử nhỏ nhất trong số đó, rồi dịch chuyển một đơn vị sang phần tử kết tiếp của phần tử nhỏ nhất đó trong mảng. Rõ ràng ta nhìn thấy ở phép so sánh và hợp nhất sử dụng Merge Sort phải tốn kém thời gian O(n*k*k) (do cần sử dụng n*k vòng lặp, mỗi vòng lặp sẽ tiến hành so sánh k phần tử một của mỗi mảng). Còn nếu thay thao tác trên nhờ sử dụng  Min Heap để chọn ra phần tử nhỏ nhất trong số k phần tử này thì chỉ cần tới log(k) thời gian, vì thế cả thảy là O(n*k*logk)

- File Mã nguồn : MergeKSortedArrays.cpp

## 6. Một số biến thể khác của Binary Heap 
- Binomial Heap : là một sự mở rộng từ Binary Heap mà cung cấp các thao tác hợp nhất các cây Binomial Heap với nhau nhanh hơn so với các thao tác hợp nhất các cây Binary Heap (thành 1 cây Binary Heap lớn).
  - Binomial Heap dựa trên ý tưởng từ cây Binomial Tree. Cây Binomial Tree có những đặc điểm sau : 
    - Cây Binomial bậc 0 thì có 1 node. Cây bậc k có thể được xây dựng bằng việc sử dụng 2 cây bậc k-1, trong đó một cây sẽ là con trái nhất của một cây còn lại.
    - Cây bậc k thì có chính xác 2^k nodes, có độ sâu bằng k,...
	
- Fibonacci Heap : là một tập hợp các cây min-heap hoặc max-heap. Trong Fibonacci Heap, các cây thành phần có thể có bất kỳ hình dạng (thậm chí có thể mọi cây thành phần đều chỉ có 1 node). Fibonacci Heap luôn duy trì một con trỏ tới giá trị nhỏ nhất (tức là một trong số các root của các cây thành phần). Các gốc cây thành phần được liên kết với nhau sử dụng danh sách liên kết đôi, nên từ một root ta luôn có thể truy cập được root chứa giá trị nhỏ nhất. Người ta nói, đây giống như một cây "lười" vì thao tác hợp nhất 2 cây min-heap thì nó đơn giản chỉ nối 2 root lại với nhau, còn với thao tác chèn thêm một node mới thì nó sẽ tạo ra một cây thành phần với chỉ một node rồi liên kết với root của cây còn lại,...

==> Đây đều là các biến thể mở rộng từ Binary Heap, tính mở rộng thể hiện ở chỗ : có khả năng "union" tức sáp nhập/liên kết nhiều cây min-heap hay max-heap lại với nhau.
- Hãy tìm hiểu thêm tính ứng dụng nếu có của các biến thể này trong thực tế !!!

  
  
  
  
  
 
