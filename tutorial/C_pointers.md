# C Pointers

Con trỏ được đánh gía là một cái gì đó thần thánh và quyền lực trong ngôn ngữ lập trình C. 

## 1. Address in C

Nếu bạn có một variable `var` trong chương trình bạn viết thì `&var` cung cấp cho bạn địa chỉ của biến đó được lưu trong memory. 

Ở đây, giá trị được nhập bởi người dùng được lưu trữ trong địa chỉ của biến `var`. Ví dụ: 

```
#include <stdio.h>
int main()
{
  int var = 5;
  printf("var: %d\n", var);
  printf("address of var: %p", &var);  
  return 0;
}
```

output

```
var: 5
address of var: 0x7ffcfcce22c4
```

## 2. C Pointers

Con trỏ (biến con trỏ) là các biến đặc biệt được sử dụng để lưu trữ địa chỉ thay vì giá trị.

### 2.1 Pointer Syntax

- Khai báo con trỏ thuộc kiểu `int`

    ```
    int* p;
    ```

- Khai báo con trỏ theo cách khác

    ```
    int *p1;
    int * p2;
    ```
- Hoặc 

    ```
    int* p1, p2;
    ```

### 2.2 Gán địa chỉ cho con trỏ

- Ví dụ: 

    ```
    int* pc, c;
    c = 5;
    pc = &c;
    ```

    Ở đây, 5 được gán cho biến c. Và địa chỉ của c được gán cho con trỏ pc.

### 2.3 Get Value

- Để lấy giá trị của biến hay một thứ gì đó được trỏ bởi con trỏ, chúng ta sử dụng toán tử  `*`. Ví dụ:

    ```
    #include <stdio.h>
    int main()
    {
        int* pc, c;
        c = 5;
        pc = &c;
        c = 1;
        printf("%d\n", c);
        printf("%d\n", *pc);
    }
    ```

    output 
    ```
    1
    1
    ```

    Tôi đã gán địa chỉ của c cho con trỏ pc. Sau đó, tôi đã thay đổi giá trị của c thành 1. Vì pc và địa chỉ của c là như nhau, *pc trả về 1.


- Một ví dụ khác 

    ```
    #include <stdio.h>
    int main()
    {
        int* pc, c, d;
        c = 5;
        d = -15;
        pc = &c; printf("%d\n", *pc); 
        pc = &d; printf("%d\n", *pc); 
    }    
    ```

    output

    ```
    5
    -15
    ```

    Ban đầu, địa chỉ của c được gán cho con trỏ pc bằng `pc = &c;` . Vì c có giá trị là 5, `*pc` cho chúng ta 5. Sau đó, địa chỉ của d được gán cho con trỏ pc bằng `pc = &d;`. Vì d có giá trị là -15, `*pc` cho chúng ta -15.

## 3. Example: Working of Pointers

```
#include <stdio.h>
int main()
{
   int* pc, c;
   
   c = 22;
   printf("Address of c: %p\n", &c);
   printf("Value of c: %d\n\n", c);  
   
   pc = &c;
   printf("Address of pointer pc: %p\n", pc);
   printf("Content of pointer pc: %d\n\n", *pc); 
   
   c = 11;
   printf("Address of pointer pc: %p\n", pc);
   printf("Content of pointer pc: %d\n\n", *pc); 
   
   *pc = 2;
   printf("Address of c: %p\n", &c);
   printf("Value of c: %d\n\n", c); 
   return 0;
}
```

output 

```
Address of c: 0x7ffcf083979c
Value of c: 22

Address of pointer pc: 0x7ffcf083979c
Content of pointer pc: 22

Address of pointer pc: 0x7ffcf083979c
Content of pointer pc: 11

Address of c: 0x7ffcf083979c
Value of c: 2
```

- `int* pc, c;`

    <img src=img/pointer-1.jpg>

    Ở đây, khởi tạo một con trỏ pc và một biến c bình thường, cả hai thuộc kiểu int. Vì pc và c ban đầu không được khởi tạo nên con trỏ pc trỏ đến không có địa chỉ hoặc địa chỉ ngẫu nhiên. Và biến c có một địa chỉ nhưng chứa giá trị ngẫu nhiên.

- `c = 22;`

    <img src=img/pointer-2.jpg>

    Gán giá trị 22 cho biến c. Nghĩa là 22 được lưu trong vị trí bộ nhớ của biến c.

- `pc = &c;`

    <img src=img/pointer-3.jpg>

    Gán địa chỉ của biến c cho con trỏ pc.

- `c = 11;`

    <img src=img/pointer-4.jpg>

    Gán giá trị 11 cho biến c.

- `*pc = 2;`

    <img src=img/pointer-5.jpg>

    Thay đổi giá trị tại vị trí bộ nhớ được con trỏ pc trỏ đến thành 2.

## 4. Những lỗi thường gặp khi làm việc với con trỏ

- Giả sử bạn muốn con trỏ pc trr đến địa chỉ c 

    ```
    int c, *pc;

    pc = c; // pc là địa chỉ nhưng c thì không

    *pc = &c; // &c là địa chỉ còn *pc thì không

    pc = &c; // cả 2 đều là địa chỉ

    *pc = c; // cả 2 đều là giá trị

    ```

- Đây là một ví dụ về người mới bắt đầu cú pháp con trỏ thường thấy khó hiểu.

    ```
    #include <stdio.h>
    int main() {
    int c = 5;
    int *p = &c;
    printf("%d", *p);  // 5
    return 0; 
    }
    ```

    Tại sao chúng tôi không gặp lỗi khi sử dụng `int *p = &c;`?

    vì 

    ```
    int *p = &c;
    ```

    tương đương với 

    ```
    int *p:
    p = &c;
    ```

    trong 2 trường hợp trên tôi đang tạo con trỏ p chứ không phải *p và gán &c cho nó. Và để tránh nhầm lẫn 

    ```
    int* p = &c;
    ```