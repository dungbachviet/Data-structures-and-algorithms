
# TÌM HIỂU VỀ CẤU TRÚC DỮ LIỆU GRAPH (ĐỒ THỊ)

*Nguồn tham khảo : https://www.geeksforgeeks.org/graph-and-its-representations/*

## 1. Đồ thị và các cách biểu diễn đồ thị
- Đồ thị là một cấu trúc dữ liệu chứa 2 thành phần chính : 
  - Tập hữu hạn Đỉnh (vertex, node)
  - Tập hữu hạn Cạnh (edge) - cặp đỉnh có thứ tự (u,v). Đối với đồ thị vô hướng (u,v) và (v,u) chỉ định cùng một cạnh, nhưng đối với đồ thị có hướng 2 cặp trên chỉ định 2 cung khác nhau. Trên mỗi cạnh (vô hướng) / cung (có hướng) có thể chứa các trọng số/giá trị/chi phí.
  
- Ứng dụng : Đồ thị được sử dụng trong biểu diễn nhiều bài toán thực tế
  - Biểu diễn mạng (network) : Mạng lưới điện thoại, mạch điện, hoặc mạng lưới thành phố... Mạng xã hội Facebook cũng sử dụng Đồ thị để biểu diễn, trong đó : mỗi khách hàng/tài khoản được biểu diễn bởi 1 đỉnh (node), mỗi đỉnh (node) sẽ chứa các thông tin của khách hàng đó như : Id, name, gender, ... Các cung nối giữa các đỉnh có thể biểu diễn quan hệ giữa các khách hàng (quan hệ bạn bè, ...)  
  - Với cách biểu diễn bởi Đồ thị, có rất nhiều các thuật toán hiệu quả trong giải quyết các bải toán thực tế trên đồ thị (sẽ trình bày trong các phần tiếp theo)
  
- 2 cách biểu diễn đồ thị thông dụng và phổ biến nhất : 
  - Ma trận kề (Adjacency Matrix) : 
    - Là một ma trận 2 chiều với kích thước VxV (với V là số đỉnh trong đồ thị). Trong đó, adj[i][j]=1 cho biết giữa 2 đỉnh i và j có một cạnh nối ở giữa, ngược lại adj[i][j]=0 khi không có cạnh nối nào giữa chúng. Chú ý : Ta có thể đặt các giá trị trọng số/chi phí... trên các cạnh nối adj[i][j] này.
	- Áp dụng : Đồ thị có hướng, Đồ thị vô hướng, Đồ thị có trọng số
	- Ưu điểm : Truy vấn Đỉnh i và Đỉnh j có kề nhau hay không với thời gian O(1) 
	- Nhược điểm : Kích thước lưu trữ luôn là O(V^2) dù đồ thị đó có là đồ thị thưa
	
  - Danh sách kề (Adjacency List)
    - Là một mảng gồm V danh sách liên kết (với V là số đỉnh trong đồ thị). Mỗi danh sách liên kết i chứa các đỉnh kề với đỉnh i này trong đồ thị. Với đồ thị có trọng số, ta chỉ cần lưu trọng số giữa 2 đỉnh này trong một trường weight trong node kề đó trong danh sách liên kết.
	- Áp dụng : Đồ thị có hướng, Đồ thị vô hướng, Đồ thị có trọng số
	- Ưu điểm : Không gian lưu trữ O(|V|+|E|)
	- Nhược điểm : Tốn kém thời gian khi trả lời truy vấn Đỉnh i có hay không kề với Đỉnh j. Do phải duyệt hết danh sách kề của một trong hai đỉnh đó ==> Mất O(V) (trường hợp xấu nhất khi đỉnh i kề với |V|-1 đỉnh còn lại)

  - Cài đặt : 
    - GraphRepresentation.cpp : Cài đặt về Danh sách kề sử dụng C (tự xây dựng cấu trúc dữ liệu)
	- GraphRepresentation1.cpp : Cài đặt danh sách kề sử dụng cấu trúc vector<> có sẵn trong C++. Vector là một cấu trúc dữ liệu lưu trữ các phần tử liền kề, liên tiếp nhau trong không gian bộ nhớ, tuy nhiên nó có khả năng tự động mở rộng kích thước của size của vector, cũng như tự động tái cấp phát sang một vùng nhớ liên tiếp khác nếu vùng nhớ liên tiếp hiện tại không còn đủ dung lượng chứa liên tiếp.
	
## 2. Duyệt đồ thị theo chiều rộng (Breath First Traversal - BFS)
- Tham khảo : https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

- Tìm kiếm theo chiều rộng đối với đồ thị cũng khá tương tự đối với kỹ thuật tìm kiếm theo chiều rộng đối với Cây (Tree), chỉ khác ở Tree thì Graph có thể chứa chu trình bên trong nó còn Tree thì không. Do vậy trong quá trình duyệt đồ thị rất dễ bị xảy ra tình huống một đỉnh (node) bị duyệt lại nhiều lần (do nằm trong chu trình). Để tránh tình trạng này, chúng ta sẽ sử dụng thêm một mảng Thăm : visited[] nhằm lưu lại các đỉnh đã được thăm (đã đi qua) để không bao giờ phải thăm lại đỉnh đó nữa.
- Để đơn giản, ta xét đồ thị liên thông (nghĩa là : từ một đỉnh luôn đi đến được mọi đỉnh còn lại)
- Tư tưởng chính : 
  - Xét một đỉnh xuất phát bất kỳ. Đưa đỉnh xuất phát vào một hàng đợi (queue), đồng thời đánh đấu đỉnh này là đã thăm. Lấy ra (và loại bỏ) phần tử s đầu tiên của hàng đợi (chính là lấy ra đỉnh xuất phát). In ra màn hình đỉnh này
  - Chọn tập đỉnh kề với đỉnh s (mà chưa được thăm). Đưa lần lượt các đỉnh này vào queue, đồng thời đánh dấu đã thăm. Lấy ra một phần tử đầu tiên trong hàng đợi, in phần tử này ra màn hình, rồi chọn tập đỉnh chưa được thăm mà kề với nó (để đưa vào hàng đợi)...
  - Cứ như vậy, tới khi Hàng đợi rỗng cũng chính là thời điểm quá trình duyệt toàn bộ đỉnh trong đồ thị hoàn tất.
  
- Trong bài viết này tác giả sử dụng các biểu diễn đồ thị bằng kỹ thuật : Danh sách kề (Adjacency List - Chứa danh sách đỉnh kề của mỗi đỉnh trong đồ thị)

- File mã nguồn : BreathFirstSearch.cpp

## 3. Các ứng dụng của Tìm kiếm theo chiều rộng
- Đường đi ngắn nhất và Cây khung nhỏ nhất (bao phủ toàn bộ đỉnh của đồ thị, mỗi đỉnh duy nhất 1 lần, và không tạo thành chu trình) cho đồ thị không có trọng số (tức các cạnh đều có cùng giá trị) : 
  - Trong đồ thị không có trọng số, đường đi ngắn nhất giữa 2 đỉnh chính là đường đi với số cạnh nhỏ nhất giữa 2 đỉnh đó. Kỹ thuật tìm kiếm theo chiều rộng luôn tìm được đường đi với số cạnh nhỏ nhất giữa 2 đỉnh cho trước (còn Kỹ thuật tìm kiếm theo chiều sâu thì không thể)
  - Với đồ thị không có trọng số (hiểu trọng số trên mọi cạnh đều bằng nhau), mọi cây khung thì đều là cây khung nhỏ nhất. Chú ý : khái niệm cây khung là cây (không có chu trình) mà chứa toàn bộ các đỉnh của đồ thị, mỗi đỉnh xuất hiện duy nhất một lần. Cây khung nhỏ nhất là cây khung có tổng trọng số trên các cạnh là nhỏ nhất (do là đồ thị không có trọng số, nên cây khung cũng chính là cây khung nhỏ nhất). Do vậy, việc sử dụng Tìm kiếm theo chiều rộng hoặc tìm kiếm theo chiều sâu đều tìm được cây khung nhỏ nhất này vì các kỹ thuật này đều chỉ duyệt qua mỗi đỉnh đúng một lần (do đã có mảng visted[] đã dấu tránh thăm quá 1 lần), nên ta chỉ cần nối các đỉnh theo trình tự thăm đó sẽ được một cây khung nhỏ nhất.
  
- Mạng Peer to Peer : là mạng kết nối trực tiếp peer to peer như BitTorrent. Người ta sử dụng Kỹ thuật tìm kiếm theo chiều rộng để tìm ra tất cả các nodes hàng xóm của nó.

- Crawlers trong các công cụ tìm kiếm : Tư tưởng là bắt đầu từ một trang web nguồn, ta sẽ folow theo mọi link trong nguồn đó, rồi cứ làm tương tự... Sử dụng kỹ thuật Tìm kiếm theo chiều rộng sẽ giúp ta hạn chế được độ sâu tìm kiếm so với Kỹ thuật tìm kiếm theo chiều sâu.

- Hệ thống định vị GPS : Sử dụng BFS trong tìm kiếm tất cả các vị trị hàng xóm (kế cạnh)

- Broadcasting (phát tán) trong mạng : Một gói tin broadcast sẽ được phát tán cho toàn node trong mạng (nhờ sử dụng BFS trong duyệt hết mọi node trong mạng đó)

- Phát hiện chu trình trong đồ thị vô hướng : 
  - Với đồ thị vô hướng : BFS hoặc DFS đều có thể được sử dụng để phát trình chu trình
  - Với đồ thị có hướng : Chỉ DFS mới phát hiện được

- Tìm luồng cực đại theo giải thuật Ford-Fulkerson : Có thể sử dụng cả BFS hoặc DFS trong tìm kiếm luồng cực đại. Nhưng BFS được ưu tiên hơn vì giúp giảm được độ phức tạp tìm kiếm

- Kiểm tra một đồ thị có là Bipartite (đồ thị 2 phía, tức đồ thị mà có thể tách tập đỉnh V thành 2 phần không giao nhau sao cho mọi cạnh thuộc đồ thị buộc phải có một đỉnh thuộc phần đỉnh này và đỉnh còn lại thuộc phần đỉnh kia)
  - Có thể sử dụng BFS hoặc DFS để giải quyết với ý tưởng chính như sau : Một đồ thị là đồ thị 2 phía khi và chỉ khi tập các đỉnh trong đồ thị đó có thể tô được bởi 2 màu sau đó 2 đỉnh kề nhau phải khác màu ==> Dựa vào tính chất này, ta sẽ sử dụng BFS hoặc DFS để thực hiện quá trình duyệt đồng thời tô màu cho các đỉnh được thăm. Tại một thời điểm duyệt nào đó, nếu phát hiện một đỉnh bị vi phạm (không thể được tô bởi 1 trong 2 màu) thì ta có dừng thuật toán và khẳng định đồ thị không là đồ thị 2 phía. Ngược lại, kết thúc giải thuật, không phát hiện đỉnh nào xung đột thì đồ thị là đồ thị 2 phía. Đồng thời ta cũng có thể tách được 2 tập đỉnh được tô bởi 2 màu khác nhau từ đồ thị trên.
  
- Kiểm tra tất cả các node trong thuộc một thành phần liên thông không?
  - Sử dụng BFS hoặc DFS để duyệt. Sau quá trình duyệt nếu còn đỉnh chưa được duyệt, chứng tỏ đỉnh đó nằm ở 1 thành phần liên thông khác, tức tập các đỉnh này không thuộc cùng một thành phần liên thông, và ngược lại.
  
- Ngoài ra, các giải thuật như Tìm kiếm cây khung nhỏ nhất của Prim hay Tìm kiếm đường đi ngắn nhất từ một đỉnh xuất phát của Dijkstra sử dụng cấu trúc hay tư tưởng tương tự với kỹ thuật BFS 

## 4. Tìm kiếm theo chiều sâu (Depth First Search - DFS)
- Tham khảo : https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

- Tìm kiếm theo chiều sâu đối với đồ thị cũng khá tương tự đối với kỹ thuật tìm kiếm theo chiều sâu đối với Cây (Tree), chỉ khác ở Tree thì Graph có thể chứa chu trình bên trong nó còn Tree thì không. Do vậy trong quá trình duyệt đồ thị rất dễ bị xảy ra tình huống một đỉnh (node) bị duyệt lại nhiều lần (do nằm trong chu trình). Để tránh tình trạng này, chúng ta sẽ sử dụng thêm một mảng Thăm : visited[] nhằm lưu lại các đỉnh đã được thăm (đã đi qua) để không bao giờ phải thăm lại đỉnh đó nữa.
- Để đơn giản, ta xét đồ thị liên thông (nghĩa là : từ một đỉnh luôn đi đến được mọi đỉnh còn lại)
- Tư tưởng chính : 
  - Sử dụng kỹ thuật ngăn xếp nhằm lưu lại những đỉnh đã đi qua nhưng chưa duyệt hết mọi đỉnh kề với nó
  - Chọn một đỉnh xuất phát. Đẩy đỉnh này vào ngăn xếp và đánh dấu đã thăm. Chọn 1 đỉnh kề với nó mà chưa được thăm. Đẩy đỉnh này vào ngăn xếp và đánh dấu đã thăm. Chọn một đỉnh kề với nó mà chưa được thăm. Rồi lại đẩy vào hàng đợi....
  - Cho tới khi, tại một thời điểm ta không thể tìm thấy bất cứ một đỉnh kề chưa được thăm nào của đỉnh đang xét. Ta loại bỏ ngăn xếp của đỉnh hiện tại, và xét ngăn xếp tiếp theo ứng với một đỉnh (mà đã được đẩy vào trước đó), rồi lại xét,...
  - Cứ như vậy cho tới khi ngăn xếp rỗng, nghĩa là quá trình duyệt tất cả đỉnh hoàn tất (đang xét với đồ thị liên thông)
  - Lưu ý thêm rằng : Ta hiểu 1 ngăn xếp sẽ chứa 1 đỉnh với thông tin về trạng thái của đỉnh đó như (trong quá khứ đã từng duyệt được những đỉnh kề nào của nó và đỉnh kề chưa thăm cần duyệt tiếp theo là gì,...). Đọc code ta sẽ dễ hiểu hơn!
  
- Trong bài viết này tác giả sử dụng các biểu diễn đồ thị bằng kỹ thuật : Danh sách kề (Adjacency List - Chứa danh sách đỉnh kề của mỗi đỉnh trong đồ thị)
- File mã nguồn : DepthFirstSeach.cpp

## 5. Các ứng dụng của kỹ thuật Tìm kiếm theo chiều sâu
- Tham khảo : https://www.geeksforgeeks.org/applications-of-depth-first-search/

- Một số ứng dụng : 
  - Với đồ thị không có trọng số, DFS có thể đưa ra được cây khung nhỏ nhất (có số cạnh nhỏ nhất), và all pair shortest path tree ?
  - Phát hiện chu trình trong đồ thị
  - Tìm đường đi giữa 2 đỉnh cho trước
  - Sắp xếp Topo : ứng dụng trong lập lịch các công việc có tính phụ thuộc lẫn nhau,...
  - Kiểm tra đồ thị có là đồ thị 2 phía
  - Tìm thành phần liên thông mạnh của một đồ thị có hướng 
  
## 6. Phát hiện chu trình trong đồ thị có hướng
- Ý tưởng chính : 
  - Sử dụng kỹ thuật Tìm kiếm theo chiều sâu DFS để phát hiện chu trình trong đồ thị
  - Quá trình duyệt DFS cho đồ thị sẽ tạo thành một cây DFS (với gốc là đỉnh xuất phát). Cây DFS phản ánh quá trình duyệt đỉnh của kỹ thuật Tìm kiếm theo chiều sâu. Cạnh trên cây DFS được phân thành 2 loại : 
    - Cung thuận : Là cung mà tại thời điểm xét nó thì nó hướng từ đỉnh đang xét tới đỉnh kề với nó mà chưa được thăm. Bản chất, thì cung thuận chính là cung giúp ta truy vết hay nhìn nhận được quá trình duyệt đỉnh trên đồ thị.
	- Cung nghịch : Là cung có hướng từ một đỉnh đang xét tới một đỉnh đã thăm nhưng chưa duyệt xong (nghĩa là tại thời điểm xét thì đỉnh đó vẫn còn nằm trong ngăn xếp). Nếu một đồ thị mà tồn tại cung nghịch khi và chỉ khi đồ thị đó tồn tại chu trình chứa cung nghịch đó. Trong phần này hãy để tâm tới cụm từ "đã thăm nhưng chưa duyệt xong" bởi vì nếu chưa duyệt xong tức đỉnh đó vẫn còn trong ngăn xếp nên việc đỉnh đang xét có đường đi tới nó mới tạo thành chu trình, còn nếu như đỉnh "hàng xóm" là đỉnh "đã thăm và cũng đã duyệt xong" tức đỉnh hàng xóm không còn nằm trong ngăn xếp nữa, cụ thể hơn những đỉnh cùng nằm trong ngăn xếp là những đỉnh khi và chỉ khi có tồn tại một đường đi qua tất cả các đỉnh đó. Vì vậy, khi đỉnh hàng xóm không còn nằm trong ngăn xếp và đã được duyệt rồi, thì không thể nào tồn tại chu trình nào đi qua nó được! (Lý thuyết này đã được chứng minh rồi)
	- Ngoài ra, cây DFS còn xét thêm 2 loại cung nữa. Ta xin không được phép trình bày tại đây (vì ít dùng đến). Nhưng bất kỳ một cung trong đồ thị ban đầu, khi được chuyển sang cây DFS sẽ được đóng vai trò : hoặc là cung thuận, hoặc là cung nghịch, hoặc là một trong hai cung còn lại.
	
==> Từ đó, ta cần phải lồng ghép cách phát hiện cung ngược vào thủ tục DFS ==> Nếu phát hiện thì đồng nghĩa với việc đồ thị có chứa chu trình !!!
  
  
  
## 7. Phát hiện chu trình trong đồ thị vô hướng
- Ý tưởng 1 : Sử dụng cấu trúc dữ liệu  disjoint-set data structure (giám sát các tập không giao nhau)
  - Tính chất : Đồ thị đơn vô hướng có n đỉnh và >= n cạnh thì luôn tồn tại ít nhất một chu trình trong nó. Từ tính chất này, ta chỉ cần kiểm soát cơ chế kiểm soát n cạnh là đủ để biết đồ thị có chứa chu trình hay không.
  - Tư tưởng chính : Người ta xây dựng các tập subset chứa tập đỉnh phân biệt. Ý nghĩa của một subset chính là một cây khung (không có chu trình) bao phủ được toàn bộ các đỉnh trong subset này. Do vậy, trong quá trình hình thành subset (cây khung), nếu phát hiện thấy cạnh nào mới mà cả 2 đỉnh của cạnh đó đều thuộc cùng một subset nào đó, điều đó tương đương với việc cạnh đó sẽ tạo thành chu trình trong subset hay cây khung hiện tại. Tới đây thuật toán kết thúc. Còn nếu sau khi xét hết toàn bộ các cạnh trong đồ thị mà không phát hiện thấy cạnh nào như vậy thì khẳng định đồ thị không có chu trình.
  - Cài đặt thực tế : Do ta cần phải phân thành nhiều subset, ta cần phải có một cơ chế định danh cho từng subset để phân biệt các subset với nhau. Với một subset cần phải được đại diện bởi một cá nhân tiêu biểu (1 đỉnh - hiểu như trưởng làng vậy), sao cho với một đỉnh bất kỳ ta luôn có thể có một cơ chế giúp tìm được trưởng làng của ngôi làng (subset) chứa đỉnh này là gì. Theo thời gian trưởng làng có thể bị thay đổi, nhưng yếu tố bất biến là : một cá nhân trong làng đó luôn biết được trưởng làng của họ.
    - Ban đầu, ta khởi tạo n subset, mỗi đỉnh trong đồ thị nằm trong mỗi subset đó, nghĩa là mỗi đỉnh đều là trưởng làng trong subset của nó.
	- Tiếp theo, là quá trình hợp nhất các làng và bầu ra trưởng làng mới. Tại sao phải hợp nhất (union) các làng, bởi vì : xuất hiện một cạnh (một mối quan hệ) mà có 1 đỉnh thuộc subset này và một đỉnh thuộc subset còn lại. Do vậy, ta cần phải hợp nhất 2 làng (2 subset) về thành 1 subset và bầu lại trưởng làng mới từ 2 làng được hợp nhất. Đơn giản, ta chỉ cần chọn ngẫu nhiên một trong hai trưởng làng cũ của 2 làng để được làng trưởng làng mới.
	- Với tư tưởng này, tác giả đã sử dụng một mảng chứa n thành phần tương ứng cho n đỉnh. Với mỗi thành phần sẽ lưu đỉnh cha của nó. Như vậy với quá trình tìm một cách đệ quy ta sẽ tìm ra được tổ tiên lớn nhất của 1 đỉnh (tức cha của cha của cha... của đỉnh đó), ta hiểu tổ tiên này chính là "trưởng làng" hay người đại diện như theo cách nói ở trên. Những đỉnh mà có cùng tổ tiên thì sẽ thuộc cùng một subset. Do vậy, khi xuất hiện một cạnh mà có 2 đỉnh thuộc 2 subset khác nhau (tức có 2 tổ tiên khác nhau), thì ta chỉ việc quyết định ngẫu nhiên xem tổ tiên nào sẽ bị làm "con" của tổ tiên nào. Sau khi quyết định xong thì rõ ràng 2 subset đã được hợp nhất thành 1 subset với chung tổ tiên. Ta cứ duyệt lần lượt từng cạnh trong đồ thị, nếu xuất hiện cạnh nào đó mà 2 đỉnh đều thuộc cùng một subset (tức cùng một tổ tiên) thì 2 đỉnh đó sẽ tạo thành chu trình trong subset đó ==> Thuật toán dừng lại. Nếu không tìm thấy cạnh nào như thế thì đồ thị không chứa chu trình.
  	
  - Nhận xét : Độ phức tạp của thuật toán chỉ là O(E*log(V)) vì phải duyệt qua E cạnh, với mỗi đỉnh trên mỗi cạnh đó phải truy vết tổ tiên tức mất thêm O(|V|) nữa. ==> Độ phức tạp khá lớn ==> Cần xây dựng một ý tưởng khác !!!
  
- Ý tưởng 2 : Sử dụng DFS (Tìm kiếm theo chiều sâu)
  - Cũng tương tự như quá trình tìm kiếm chu trình trong đồ thị có hướng sử dụng DFS, bây giờ ta sẽ sử dụng DFS trong phát hiện chu trình trong đồ thị vô hướng
  - Tư tưởng chính : Trong quá trình xây dựng cây DFS, tại một thời điểm nào đó, nếu phát hiện có đỉnh kề với đỉnh đang xét là một đỉnh đã thăm và không phải là cha của đỉnh đang xét (đỉnh cha được hiểu là đỉnh cha của đỉnh đang xét trong cây DFS, rõ ràng đỉnh cha này ngay trên đỉnh đang xét nên không được tính đỉnh cha này!!!) ==> Thì đồ thị có chứa chu trình. Ngược lại, nếu trong toàn bộ quá trình hình thành cây DFS nếu ta không tìm thấy được cạnh nào như thế thì đồ thị vô hướng là không tồn tại chu trình.
  
  - Độ phức tạp : O(V+E) (khá nhanh so với ý tưởng trước) (độ phức tạp tuyến tính)  
  
## 8. Sắp xếp Topo
- Bài toán sắp xếp Topo : Từ một đồ thị có hướng không có chu trình (DAG) ta cần phải chỉ ra một dãy các đỉnh theo thứ tự Topo sao cho với mỗi cung bất kỳ a-->b thì a luôn phải đứng trước b trong dãy đó.

- Giải thiết : Đồ thị có hướng phải không được có chu trình thì mới tồn tại một cách sắp xếp các đỉnh theo thứ tự Topo

- Nhận xét : 
  - Trong dãy sắp xếp Topo thì rõ ràng đỉnh ở đầu dãy phải là đỉnh có bán bậc vào = 0 (tức không thể có cung đi vào) (vì nếu có thì chắc chắn phải có một đỉnh khác phía trước nó trong dãy topo này)
  - Đỉnh ở cuối dãy Topo phải là đỉnh có bán bậc ra = 0 (tức không có cung đi ra khỏi nó) (vì nếu có một cung ra từ đỉnh này thì chắc chắn phải tồn tại một đỉnh khác phía sau nó trong danh sách topo)


- Ý tưởng :
  - Ta sử dụng một Stack đẩy lần lượt các đỉnh được duyệt trong quá trình DFS. Để sau này khi in Stack thì ta sẽ có một danh sách ngược lại với các đỉnh theo thứ tự duyệt "sớm hơn" theo chiều từ trái sang phải. Danh sách này chính là danh sách theo thứ tự Topo
  - Dựa vào tính chất : những đỉnh càng được duyệt sớm trong DFS (Duyệt theo chiều sâu) thì càng sẽ đứng ở cuối trong danh sách Topo, ngược lại những đỉnh càng bị duyệt muộn là những đỉnh sẽ càng ở đầu của dãy Topo. Ta có thể giải thích tính chất này như sau : 
    - Xét một đỉnh ở trạng thái đã được duyệt : 
	  - Các cung ra của đỉnh này : chắc chắn sẽ nối với đỉnh mà đã được duyệt trước đó rồi. Điều này giúp đảm bảo tính đúng đắn trong thứ tự topo
	  
  
 