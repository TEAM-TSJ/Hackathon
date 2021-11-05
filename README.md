# 라피신 (La Piscine)
Did you heard about..

## Index
<details>
<summary>open/close</summary>
<div markdown="1">

Chapter   I. General rules<br>
Chapter  II. Foreword<br>
Chapter III. Exercise 00:<br>
Chapter  IV. Exercise 01:<br>
Chapter   V. Exercise 02:<br>
Chapter  VI. Exercise 03:<br>


</div>
</details>

# Chapter I General rules

<details>
<summary>open/close</summary>
<div markdown="1">

 ex) 금지된 함수 사용시 0점. . . ..<br>
 ex) 작성한 챕터에대해서 설명할수있어야함.<br>
 ex) C언어를 사용합니다.<br>
 ex) 출력은 라이트 쓰세요<br>
 ex) 메모리릭관리는 철저해야합니다.<br>
 ex) 치팅금지.
 ex) 원피스 보지마세요 . tjung <br>
 
</div>
</details>


# Chapter II 허프만(Huffman)

<br>

## Exercise : 00. text.txt

|*Exercise : 00*|
|-----------------|
|Turn-in directory : huffman/|
|Files to turn in : text.txt, Every other files you need|
|Forbidden functions : None|

* 다음과 같은 내용의 text.txt를 생성합니다.
```
"We make a Piscine"
```
<br>
🚨 텍스트의 내용이 온전해야합니다.

```
/hackathon ls -al text.txt
-rw-r--r--  1 junseoplee  staff  20 11  5 17:30 text.txt
```

<br>
<br>

## Exercise : 01. ft_huffman

|*Exercise : 01*|
|-----------------|
|Turn-in directory : huffman/|
|Files to turn in : text.txt, main.c, huffman.c|
|Forbidden functions : None|

* text.txt의 내용을 활용하여 허프만트리를 만들어주는 기능함수를 작성합니다. 
* 기능함수의 프로토타입은 다음과 같습니다.
```
t_node *ft_huffman(char *str);
```
<br>
💡 허프만트리 https://en.wikipedia.org/wiki/Huffman_coding
<br>
<br>

## Exercise : 02. ft_preorder
 
|*Exercise : 02*|
|-----------------|
|Turn-in directory : huffman/|
|Files to turn in : main.c, Every other files you need|
|Forbidden functions : None|

* 작성한 텍스트내용을 활용하여 허프만트리를 탐색하는 기능 함수를 만듭니다.
* 기능함수의 프로토타입은 다음과 같습니다.
```
void ft_preorder(t_node *tree);
```
<br>

* 기대되는 출력결과는 다음과 같습니다.
```
 /hackathon ./huffman text.txt
20 12 7 4 2 2 3 5 3 2 1 1 8 4 2 1 1 2 1 1 4 2 1 1 2 %
```
<br>
<br>

## Exercise : 03. ft_inorder

|*Exercise : 03*|
|-----------------|
|Turn-in directory : huffman/|
|Files to turn in : main.c, Every other files you need|
|Forbidden functions : None|
 
* 작성한 텍스트내용을 활용하여 허프만트리를 탐색하는 기능 함수를 만듭니다.
* 기능함수의 프로토타입은 다음과 같습니다.
```
void ft_inorder(t_node *tree);
```
<br>

* 기대되는 출력결과는 다음과 같습니다.
```
/hackathon ./huffman text.txt
2 4 2 7 3 12 3 5 1 2 1 20 1 2 1 4 1 2 1 8 1 2 1 4 2 %
```

<br>
<br>

## Exercise : 04. ft_postorder
 
|*Exercise : 04*|
|-----------------|
|Turn-in directory : huffman/|
|Files to turn in : main.c, Every other files you need|
|Forbidden functions : None|

* 작성한 텍스트내용을 활용하여 허프만트리를 탐색하는 기능 함수를 만듭니다.
* 기능함수의 프로토타입은 다음과 같습니다.
```
void ft_postorder(t_node *tree);
```
<br>

* 기대되는 출력결과는 다음과 같습니다.
```
 /hackathon ./huffman text.txt
2 2 4 3 7 3 1 1 2 5 12 1 1 2 1 1 2 4 1 1 2 2 4 8 20 %
```
 
<br>
<br>


# Chapter III 파일 포맷

<br>

## Exercise : 01. header data

|*Exercise : 01*|
|-----------------|
|Turn-in directory : foramt/|
|Files to turn in : test.txt, main.c, Every other files you need|
|Forbidden functions : None|

* 파일압축을 위한 정보를 담는 함수를 작성해야합니다.
* 아래 정보는 필수로 담겨야만 합니다.
  * 사용된 문자의 갯수.
  * 문자의 아스키코드.
  * 변환된 문자의 길이.
  * 변환된문자.

<br>
🚨 정보의 순서가 틀림없어야 합니다. 또한 출력된 결과를 설명할 수 있어야합니다.
<br>
<br>

* 기능함수의 프로토타입은 다음과 같습니다.
```
void ft_tranlator(char *str);
```

* 기대되는 출력결과는 다음과 같습니다.
```
 /hackathon ./foramt text.txt
00001101

001000100011111

0101011101001101

011001010011001

001000000011010

0110110101001100

0110000101000001

0110101101001011

0101000001001010

0110100101000000

0111001101001001

0110001101001000

0110111001000111

0000101001000110

00000000000000000000000001001000

11111010010101100000110110010100
00101010100000100110000000011100
11110110

...
```
<br>
<br>


# Chapter IV 인코딩 출력

<br>
<br>

# Chapter VI 디코딩 출력

<br>
<br>

# Chapter VII 통합 프로그램 만들기

<br>
<br>

# Chapter VIII zip 무손실 컨테이너 구현

<br>
<br>


