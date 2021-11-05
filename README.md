# 라피신 (La Piscine)

# Chapter I 작성규칙

<details>
<summary>open/close</summary>
<div markdown="1">

<br>
42라면 누구나 알고있는 그 룰을 따르세요.
<br>

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

* 다음 문자열이 담긴 text.txt를 생성합니다.
```
"We make a Piscine"
```

<br>

🚨 텍스트의 내용은 온전해야합니다. 크기를 반드시 확인하세요.

<br>

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

## Exercise : 00. header data

|*Exercise : 00*|
|-----------------|
|Turn-in directory : foramt/|
|Files to turn in : test.txt, main.c, Every other files you need|
|Forbidden functions : None|

* 파일압축을 위한 정보를 '이진수'로 담는 함수를 작성해야합니다.
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

<br>

* 기대되는 출력결과는 다음과 같습니다.
* 이전챕터의 text.txt파일과 동일한 파일을 사용하세요.
* 실제결과는 개행이 출력되지않습니다.
```
 /hackathon ./foramt text.txt | cat -e
00001101$
$
001000100011111$$
$
0101011101001101$
$
011001010011001$
$
001000000011010$
$
0110110101001100$
$
0110000101000001$
$
0110101101001011$
$
0101000001001010$
$
0110100101000000$
$
0111001101001001$
$
0110001101001000$
$
0110111001000111$
$
0000101001000110$
$
00000000000000000000000001001000$
$
11111010010101100000110110010100$
00101010100000100110000000011100$
11110110$
$
...
```
<br>
<br>


# Chapter IV 인코딩

<br>

## Exercise : 00. encode

<br>

|*Exercise : 00*|
|-----------------|
|Turn-in directory : encode/|
|Files to turn in : filename.txt, main.c, main.h, Makefile|
|Forbidden functions : None|

* 파일정보를 읽어 크기를 압축하는 프로그램을 작성합니다.
* 압축된 파일의 확장자는 '.bin'입니다.
* 확장자를 제외한 파일이름이 동일해야합니다.

<br>

* 기대되는 출력결과는 다음과 같습니다.
```
junselee /hackathon ls -al junselee.txt
-rw-r--r--  1 junseoplee  staff  551 11  6 00:01 junselee.txt
junselee /hackathon ./encode junselee.txt
junselee /hackathon ls -al junselee.bin
-rw-r--r--  1 junseoplee  staff  268 11  6 00:02 junselee.bin
```

<br>
<br>

# Chapter VI 디코딩

<br>

## Exercise : 00. decode

<br>

|*Exercise : 00*|
|-----------------|
|Turn-in directory : decode/|
|Files to turn in : filename.bin, main.c, main.h, Makefile|
|Forbidden functions : None|

* 압축된파일을 되돌리는 프로그램을 작성합니다.
* 압축해제된 파일의 확장자는 '.txt'입니다.
* 확장자를 제외한 파일이름이 동일해야합니다.

<br>

* 기대되는 출력결과는 다음과 같습니다.
```
/hackathon ls -al junselee.bin
-rw-r--r--  1 junseoplee  staff  268 11  6 00:02 junselee.bin
/hackathon ./huffman_coding_program -d junselee.bin
/hackathon ls -al junselee.txt
-rw-r--r--  1 junseoplee  staff  551 11  6 00:07 junselee.txt
```
<br>

🚨 압축의 효율은 생각하지마세요! 문제없는 프로그램은 그 자체로 충분히 아름답습니다.

<br>

# Chapter VII 통합 프로그램 만들기

<br>
<br>

# Chapter VIII zip 무손실 컨테이너 구현

<br>
<br>


