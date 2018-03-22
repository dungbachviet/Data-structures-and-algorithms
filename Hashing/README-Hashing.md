
# TÌM HIỂU VỀ CẤU TRÚC DỮ LIỆU HASHING (BẢNG BĂM)

### *Nguồn tham khảo :https://www.geeksforgeeks.org/data-structures/*

## 1. Giới thiệu về Bảng Băm (Hashing)
https://www.geeksforgeeks.org/hashing-set-1-introduction/

- Bài toán đặt ra : Trong một hệ thống lưu trữ các bản ghi thông tin của nhân viên sử dụng khóa chính (key) là số điện thoại. Với một hệ thống cơ sở dữ liệu này, những truy vấn sau cần phải được thực hiện một cách hiệu quả như : 
  - Chèn một số điện thoại (key) cùng bản ghi thông tin nhân viên
  - Tìm kiếm một bản ghi (chi tiết) thông tin của một nhân viên khi biết số điện thoại của nhân viên đó
  - Xóa toàn bộ thông tin của nhân viên mà gắn với một số điện thoại cụ thể

- Đầu tiên, ta cần hiểu kỹ hơn về vấn đề của bài toán : Hệ thống luôn cất giữ một tập các thông tin chi tiết về nhân viên của họ (họ tên, quê quán, số điện thoại, tuổi, nơi sinh,...) dưới khuôn dạng các bản ghi trong một vùng nhớ xác định. Lúc này vùng nhớ đang tồn tại rất nhiều bản ghi thông tin, vì vậy việc tìm kiếm thông tin của 1 nhân viên cụ thể khiến ta phải duyệt gần như toàn bộ các bản ghi trong hệ thống (tức với độ phức tạp O(n)). Với các thao tác chèn, xóa có cùng độ phức tạp tương tự như thao tác tìm kiếm. Lúc này, người ta mới nghĩ tới một giải pháp giúp tìm kiếm nhanh hơn một bản ghi trong hệ thống(vùng nhớ) ===> Ý tưởng về Bảng băm ra đời !!!

- Trước khi đề cập tới Bảng Băm (Hash Table) ta sẽ đề cập tới một vài cách lưu trữ truyền thống với các cấu trúc dữ liệu thông dụng (mà chưa sử dụng Bảng Băm) như sau : 
  - Sử dụng Mảng hoặc Danh sách liên kết : Đầu tiên ta cần định nghĩa ra một cấu trúc dữ liệu riêng cho việc lưu trữ một bản ghi với các trường thông tin chính như sau : key (số điện thoại) và data chi tiết khác (họ tên, tuổi, năm sinh), con trỏ tới bản ghi kế tiếp (nếu sử dụng linked list). Lúc này có 2 khả năng xảy ra : 
    - Hoặc là các bản ghi này sẽ được lưu trữ vào trong mảng hay linked list không theo một thứ tự gì cả ==> Điều này dẫn tới việc tìm kiếm gần như phải duyệt toàn bộ các bản ghi có trong Mảng hay Linked List
	- Hoặc là các bản ghi được lưu trữ trong Mảng hay Linked List nhưng luôn duy trì một trật tự (tăng dần) về trường Số điện thoại trong mỗi bản ghi. Với việc duy trì tính có thứ tự, ta có thể sử dụng kỹ thuật Tìm kiếm Nhị Phân (Binary Search) để tìm kiếm một bản ghi gán với nhân viên có số điện thoại x với độ phức tạp là O(log(n)). Nhưng với các lưu trữ có thứ tự, sẽ khiến các thao tác chèn hay xóa bản ghi trở nên tốn kém!!! ==> Cách này không khả thi !
  
  - Vậy nếu lưu trữ các bản ghi nhờ sử dụng Balanced Binary Search Tree (Cây nhị phân tìm kiếm cân bằng) thì sao? (Cây nhị phân tìm kiếm - BST với tính chất Các node trên cây con trái đều nhỏ hơn node cha và node cha luôn nhỏ hơn mọi node trên cây con phải, đồng thời cây con trái và cây con phải cũng đều phải là cây nhị phân tìm kiếm). Mỗi node trên cây sẽ là một bản ghi với key là Số điện thoại, cùng với một số trường thông tin của nhân viên (họ tên, quê quán,...). Key trên mỗi node phải tuân thủ theo đặc trưng của một cây nhị phân tìm kiếm ==> Các thao tác Tìm kiếm, Chèn, Xóa trên BST đều chỉ tốn thời gian O(log(n)). Lúc này sự cản trở lớn nhất sẽ là số chữ số điện thoại có thể quá dài, khó thể lưu trữ bằng kiểu integer thông thường ==> phải lưu bằng kiểu String ==> Nhưng nếu như lưu bằng String thì sẽ phải so sánh như thế nào? (Cũng có một số kỹ thuật giúp sắp xếp các số dạng String). Tới đây có vẻ hơi phức tạp !!!
  
  - Sử dụng một bảng truy cập trực tiếp : Yêu cầu một mảng vô cùng lớn với index chính là key tức số điện thoại của nhân viên. Lúc này thao tác tìm kiếm chỉ là O(1), nhưng lại yêu cầu một vùng nhớ và sự lãng phí quá lớn. Đó còn chưa kể tới trường hợp số chữ số của điện thoại là quá dài nên không thể lưu trữ được dưới dạng số nguyên Integer

==> Với cả 3 cách tiếp cận trên : ta đều có thể chỉ xây dựng một Node chỉ 2 thành phần là Key và Tham chiếu (tới vùng nhớ khác đang thực sự chứa bản ghi). Với sự cải biến này, chúng ta vẫn phải đối mặt với vấn đề Key (quá dài) và vấn đề sử dụng thêm vùng nhớ phụ dùng cho lưu trữ các tham chiếu (con trỏ tới vùng nhớ thực)

- Với sự bất lực (có vẻ như) từ các cách tiếp cận trên, người ta đề xuất một cấu trúc dữ liệu chuyên lưu trữ các dữ liệu với đặc tính dạng Map (ánh xạ 1-1), gọi Hash Table với ý tưởng chính như sau : 
  - Sử dụng một vùng nhớ phụ lưu trữ các con trỏ (tham chiều) tới vùng nhớ thực sự của bản ghi nhân viên
  - Sử dụng một Hàm Băm (Hash Function) để chuyển (convert) một số lớn sang một số nhỏ hơn (cụ thể nó sẽ convert key sang một key mới nhỏ hơn)
  - Lúc này, với một số điện thoại x, thông qua hàm băm ta sẽ được một giá trị mới nhỏ hơn là x1 (x1 < x), khi này x1 sẽ là index của mảng con trỏ giúp ta tìm được tham chiếu thực sự đang trỏ tới vùng nhớ của bản ghi. Với con trỏ tìm được (từ index) ta có thể truy cập vào bản ghi thực sự (mà địa chỉ của nó được lưu trữ trên con trỏ) một cách dễ dàng. Bảng mà chứa danh sách các con trỏ đó người ta gọi là Bảng Băm. Trường hợp nếu ứng với một số điện thoại cụ thể mà giá trị tương ứng của nó trong bảng băm là NULL, điều này có nghĩa là : Số điện thoại này không tồn tại trong hệ thống (hay ko có bất kỳ nhân viên nào có số điện thoại này)
  
- Một số hạn chế cần phải đối mặt khi sử dụng Bảng Băm : Hiển nhiên khi sử dụng một hàm băm để chuyển đổi từ một miền không gian lớn sang một miền không gian nhỏ hơn, sẽ xảy ra tình huống là : có 2 giá trị từ miền không gian lớn ban đầu thông qua hàm băm được chuyển đổi sang cùng một giá trị trong miền không gian nhỏ hơn. Hiện tượng này người ta gọi là : Collision (Sự đụng độ). Có 2 kỹ thuật chính trong việc giải quyết vấn đề này : 
  - Kỹ thuật 1 - Separate Chaining (Nối chuỗi) : Hãy hình dung một bảng băm với các ô (cell) chứa (key + con trỏ). Số cell (số ô) chính là số lượng giá trị có thể có trong miền không gian "co hẹp" mới của hàm băm. Vì vậy, có thể sau khi đi qua hàm băm, có thể với 1 ô tồn tại nhiều giá trị key khác nhau cùng "đụng độ". Giải pháp lúc này là : nối dài các cặp (key + con trỏ) một cách liên tiếp. Sau này, khi muốn tìm kiếm một key bất kỳ, ta chỉ việc sử dụng hàm băm để tính ra index của ô (cell) trong bảng băm. Sau khi truy cập tới ô này, ta tiếp tục duyệt hết danh sách liên kết (đang nối chuỗi nhau). Nếu tìm thấy (có tìm key cần tìm) thì sử dụng con trỏ gắn với nó để truy cập tới vùng nhớ thực sự. Còn nếu duyệt hết mà không tìm thấy, nghĩa là key này không tồn tại trong hệ thống. (*Tham khảo tại: https://www.geeksforgeeks.org/hashing-set-2-separate-chaining/*)
    - Hạn chế lớn nhất : Xảy ra tình trạng xuất hiện những ô băm có danh sách liên kết nối chuỗi quá dài, nhưng có những ô băm lại không được sử dụng đến. Từ đó dẫn tới một sự lãng phí và không hợp lý !!!
  
  - Kỹ thuật 2 - Open Addressing (Không gian địa chỉ mở): Được ra đời nhằm cố gắng khác phục hạn chế từ kỹ thuật 1 với ý tưởng chính : 
    - Tận dụng hết mọi ô trong bảng băm, nhưng vẫn tránh được sự đụng độ
	- Mỗi key luôn chỉ được nằm trong nhiều nhất một ô băm, tức không có sự nối chuỗi ==> Vì thế Không gian "sau băm" (hay kích thước của bảng băm) phải lớn hơn Không gian Key ban đầu.
	- Kỹ thuật 2 có một vài cách tiếp cận như sau : 
	  - Linear Probing (Thăm dò tuần tự) : Với key x, tức với index hash(x)%S trong bảng băm nếu đã đầy (tức đã tồn tại một key khác nằm ở ô đó) thì ta chuyển sang ô tiếp theo (hash(x)+2 % S) xem đã đầy chưa? ... Cứ như cho tới khi tìm được ô trống và ta chèn key x vào ô trống đó trong bảng băm. Với thao tác tìm kiếm hoặc xóa, thì ta cũng sẽ tìm một cách tuần tự vậy cho tới khi tìm thấy key mong muốn. Nhược điểm của kỹ thuật này, đó là : hiện tượng "clustering" (phân thành cụm), nghĩa là khi các key từ Không gian gốc cứ "sat sát" nhau, dẫn tới sự phân bố không đều trong bảng băm (nghĩa là có những khu vực trong bảng băm rất đông đúc, nhưng lại có những khu vực lại vô cùng thưa thớt)
	  
	  - Quadratic Probing (Thăm dò Quadratic) : Ra đời để giải quyết hiện tượng "clustering" trong phương pháp Linear Probing. Ý tưởng là : Thay vì cứ kiểm tra lần lượt từng ô (bắt đầu từ ô hash(x)) thì ta sẽ kiểm tra một cách ngắt quãng tức theo công thức i*i (là kiểm tra tại các ô hash(x), rồi hash(x)+1*1, rồi hash(x)+2*2,... cứ như vậy có tới khi tìm thấy ô trống để có thể điền key mới vào)
	  
	  - Double Hashing : Tức sẽ kiểm tra từ các ô theo thứ tự như sau : hash(x), rồi hash(x)+1*hash2(x), rồi hash(x)+2*hash2(x), rồi hash(x)+3*hash2(x),... cứ như vậy cho tới khi tìm thấy ô trống để điền key mới vào đó !!!
	
	- Một sự so sánh nhỏ giữa : Linear Probing, Quadratic Probing và Doubling Hashing
	  - Linear Probing : có hiệu suất sử dụng cache cao nhất (vì nó kiểm tra tuần tự, nên cache có thể lấy được cả một vùng nhớ liên tiếp về cache cho việc tiện tra cứu, và đỡ phải mất công vào RAM để đọc từ Bảng Băm), nhưng lại phải đối mặt với hiện tượng Clustering (phân cụm)
	  - Quadratic Probing : Cân bằng được giữa việc sử dụng Cache hiệu quả và hạn chế được Clustering so với Linear Probing.
	  - Double Hashing : Hiệu suất sử dụng cache là tồi (vì nó tìm kiếm tại những ô cách nhau khá xa trên bảng băm, nên việc cache có lấy những vùng nhớ liên tiếp nhau trong RAM thì cũng ko có ích lợi gì cho việc tận dụng nó), nhưng phương pháp này không xảy ra hiện tượng Clustering (tức nó sẽ phân bố đều đặn trên Bảng băm)
	  
- So sánh giữa 2 kỹ thuật : Separate Chaining với Open Addressing
  - Kỹ thuật Separate Chaining : 
    - Đơn giản trong cài đặt
	- Không bao giờ bị đầy bảng băm vì nó có thể nối tạo thành các chuỗi
	- Thường được sử dụng khi mà không biết chắc số lượng key và tần suất mà các key sẽ được chèn hay xóa.
	- Có thể không tận dụng được hết các ô trong bảng băm, có thể gây quá tải cho một ô băm( khi chuỗi key trên ô đó quá dài)
  - Kỹ thuật Open Addressing : 
    - Có hiệu suất tận dụng cache cao hơn (vì các key được lưu liên tiếp trên cùng 1 bảng băm, còn với kỹ thuật chaining thì không tận dụng được bởi vì các node trong chuỗi danh sách liên kết là không liền kề trong vùng nhớ vì sử dụng con trỏ để tham chiếu tới nhau)
	- Tận dụng được vùng nhớ trong bảng băm (vì nó luôn cố gắng làm đầy các vị trí trống trong bảng băm nhờ quá trình thăm dò "probing", còn kỹ thuật Chaining sẽ gây lãng phí tại những ô băm không được dùng đến và còn tốn thêm vùng nhớ cho các con trỏ trên danh sách liên kết chuỗi key)
  
## 2. Cài đặt một Bảng băm đơn giản sử dụng kỹ thuật Double Hashing trong phương pháp Open Addressing : 
https://www.geeksforgeeks.org/double-hashing/

- Double Hashing la một trong những kỹ thuật giải quyết đụng độ trong bảng băm (collision) (đã được trình bày bên trên). Double Hashing sử dụng ý tưởng của việc áp dụng thêm một hàm băm thứ hai cho key trong thăm dò vị trí khác (khi có một sự đụng độ xảy ra)
- Công thức thăm dò (probing) : (hash1(key) + i * hash2(key)) % TABLE_SIZE
- Trong đó : 
  - hash1(key) = key % TABLE_SIZE
  - hash2(key) = PRIME – (key % PRIME) , với PRIME là một số nguyên tố nhỏ hơn kích thước của bảng băm TABLE_SIZE

- Hàm băm thứ hai hash2(key) tốt khi thỏa mãn 2 yêu cầu sau : 
  - Nó không bao giờ trả lại giá trị 0 (vì nếu trả lại giá trị 0 thì rõ ràng nó trở về lại index ban đầu được tính từ hash1())
  - Nó phải đảm bảo sẽ khám hết mọi ô trong bảng băm
  
- File mã nguồn : DoubleHashing.cpp
  
