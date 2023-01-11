# **HÀNG ĐỢI QUEUE, PRIORITY QUEUE, DEQUE**
I. **QUEUE**

1. Khai niệm 

>Hàng đợi hay queue là một cấu trúc dữ liệu động hoạt động theo cơ chế **FIFO** (**F**irst **I**n, **F**irst **O**ut), nghĩa là phần tử được thêm vào đầu tiên sẽ là phần tử được lấy ra đầu tiên.

![queue](https://happymobile.vn/wp-content/uploads/2021/09/hang-doi-1-730x430.jpg)

2. Các câu lệnh trong queue

Đầu tiên để sử dụng được queue trong C++ chúng ta cần khai báo thư viện queue :

    #include <queue>

Và khởi tạo 1 queue bằng câu lệnh sau :

    queue <kieu_du_lieu> ten_bien;

Các thao tác với queue :

VD : queue <int> q;

| Câu lệnh  |    Tác dụng                            |
|:--------- |:---------------------------------------|
| q.push(x) | thêm phần tử x vào cuối của hàng đợi   |
| q.pop()   | đẩy phần tử ở đầu ra khỏi hàng đợi     |
| q.back()  | trả về giá trị ở cuối hàng đợi         |
| q.front() | trả về giá trị ở đầu hàng đợi          |
| q.empty() | kiểm tra xem hàng đợi có rỗng hay không|
| q.size()  | trả về số lượng phần tử trong hàng đợi |

*Tất cả các thao tác trên đều có độ phức tạp O(1)*

II. **PRIORITY QUEUE**

1. Khai niệm 

>Priority Queue – Hàng đợi ưu tiên là một giải pháp mở rộng của Queue – Hàng đợi, với các thuộc tính sau:
>- Mọi phần tử đều được gắn liền với một độ ưu tiên
>- Một phần tử có độ ưu tiên cao sẽ được dequeued (xóa khỏi Priority Queue) trước một phần tử có độ ưu tiên thấp
>- Nếu hai phần tử có cùng độ ưu tiên, lúc này việc phần tử nào được xử lý trước sẽ phụ thuộc vào thứ tự của chúng ở trong Priority Queue.

![priority_queue](https://raw.githubusercontent.com/dang1412/codetube.vn-articles/main/images/Priority-Queue-Codetube-vn.png)

2. Các câu lệnh trong priority queue

Đầu tiên để sử dụng được priority queue trong C++ chúng ta cần khai báo thư viện queue :

    #include <queue>

Và khởi tạo 1 priority queue bằng câu lệnh sau :

    priority_queue <kieu_du_lieu> ten_bien;

Các thao tác với priority queue:

VD : priority_queue <int> p;

| Câu lệnh  |    Tác dụng                                    | Độ phức tạp |
|:--------- |:-----------------------------------------------|:------------|
| p.push(x) | thêm phần tử x vào hàng đợi ưu tiên            |   O(logN)   |
| p.pop()   | đẩy phần tử ở đỉnh ra khỏi hàng đợi            |   O(logN)   |
| p.top()   | trả về giá trị ở đỉnh của hàng đợi ưu tiên     |    O(1)     |
| p.empty() | kiểm tra xem hàng đợi ưu tiên có rỗng hay không|    O(1)     |
| p.size()  | trả về số lượng phần tử trong hàng đợi ưu tiên |    O(1)     |

III. **DEQUE**

1. Khai niệm 

>Thuật ngữ deque là cách gọn ngắn tắt của double-ended queue (hàng đợi hai đầu). Sở dĩ là vì nó có thể thêm, bớt phần tử ở cả hai đầu
>Deque cũng là một dạng mảng động tương tự với vector.
>Nhưng hiệu suất của deque thì không bằng vector

![deque](https://i.imgur.com/0f5hQR9.png)

2. Các câu lệnh trong deque

Đầu tiên để sử dụng được deque trong C++ chúng ta cần khai báo thư viện queue :

    #include <queue>

Và khởi tạo 1 deque bằng câu lệnh sau :

    deque <kieu_du_lieu> ten_bien;

Các thao tác với dequeue :

VD : deque <int> d;

| Câu lệnh        |    Tác dụng                            |
|:----------------|:---------------------------------------|
| d.push_front(x) | thêm phần tử x vào đầu của deque       |
| d.push_back(x)  | thêm phần tử x vào cuối của deque      |
| d.pop_front()   | đẩy phần tử ở đầu ra khỏi deque        |
| d.pop_back()    | đẩy phần tử ở cuối ra khỏi deque       |
| d.back()        | trả về giá trị ở cuối deque            |
| d.front()       | trả về giá trị ở đầu deque             |
| d.empty()       | kiểm tra xem deque có rỗng hay không   |
| d.size()        | trả về số lượng phần tử trong deque    |

Ngoài những câu lệnh ở trên ra thì deque có những câu lệnh tương tự vector như : assign(),begin(),end(),clear(),..... 

*Tất cả các thao tác trên đều có độ phức tạp O(1)*