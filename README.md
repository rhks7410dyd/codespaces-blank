# PSstoringplace
깃허브 사용 단계

- 푸쉬 과정
git add . -> git commit -> git push

To do
git add가 아닌 git add .을 사용해야 하는 이유 알아보기.

+ 깃 허브 자체에서 무엇인가 수정한 경우 git pull을 우선적으로 진행해 줘야됨.

git add Math/boj2407.cpp 와 같이 쓰면 이 파일만 add됨

- 터미널에서 특정 파일을 실행시킬 때, g++ boj11779.cpp -o test && ./test 이런 식으로 작성하면 터미널에서 파일을 실행시킬 수 있다.

# Tip3
1. C++의 벡터,스트링은 push_back, pop_back이 있어서 중간 노드를 확인할 수 있는 스택으로서 사용할 수 있다.
2. 언제나 코드를 짤 때는 수정이나 스캐폴딩 등을 위해 여러 함수로 나누어서 전역 변수를 이용하여 만드는 것이 좋다.
3. C++에서 algorithm 헤더의 next_permutation() 함수는 모든 순열을 순서대로 생성하는 작업을 해줌 (https://twpower.github.io/82-next_permutation-and-prev_permutation)
4. char의 범위는 -128 ~ 127 이므로 -1,0,1 세 가지 값으로 상태를 표현할 때는 char을 사용하면 메모리 소비를 줄일 수 있다(int의 1/4배니까 의미가 큼)
5. CCW 알고리즘 https://snowfleur.tistory.com/98
6. algorithm 헤더 upper_bound && lower_bound 함수 (https://chanhuiseok.github.io/posts/algo-55/)

# 공부 일정
1. 종만북 1권 + 토익 보카 (~5월) //이미 여기가 작살 나버림.
2. 종만북 완독 + 토익 병행 + solved.ac 클래스 5++ ~ 6까지 (~11월)
3. 백준 문제 복습 (~1월)

# 공부 일정 2
1. 종만북 1권 완독 + solved.ac 클래스 5++ + 토익 보카 + 토익(~11월)
+ 토익 공부를 낮 시간에 많이 해야됨. 왜냐하면 영단어를 찾으면서 하려고 사지방 오긴 싫음. 코딩 공부도 해야되기 때문에 매일매일 낮에 공부 + 모르는 단어 체크
+ -> 이후 개인정비 시간에 단어 찾고 외우기 + 보카 책 하나(전날꺼 복습 X 그냥 여러번 돌린단 마인드로) 
2. 종만북 1권 복습(~1월)

# Memo
1. 토익 실전모의고사 문제집
2. 한 권으로 끝내는 네트워크 기초
3. 팀 개발을 위한 Git, GitHub 시작하기
4. https://play2048.co/ 2048 html 게임 사이트

# 휴가
확정 16일(연가 9 + 위로 4 + 백신 2 + 포상 7) -> 22 확정
1안 : 12 + 10 (+5)
(5관3략 400일 + 포상 2 + 청원 1 + 보상 1 = 5일, 400일을 받는다면 이렇게 긁어모을 수 있음)

미사용 포상 휴가:
	백신 2일(기간 X) - 초과 가능
	5관 3략 300일 - 초과 가능
------------------------------------
	총 2일

지급 예정 포상 휴가:
	분대장 (4일)
	상점 200점(아직 교환 X)
------------------------------------
	총 7일

사용 포상 휴가:
	전준태 포상 4일
	5관3략 100일 1일
	5관3략 200일 1일
	독후감상문 대회 1등 2일
------------------------------------
	총 8일

초과 가능 포상 휴가 : 총 3일
초과 불가 포상 휴가 : 총 14일

총 휴가 : 연가 24일 + 포상 19일 + 위로(총 4일) = 47일(잔여 24) (+ 구직청원휴가 2일 + 보상 휴가 1일)

1차 정기 휴가 : 연가 7일 + 포상 5일(12일) <- 4/3 ~ 4/14

2차 정기 휴가 : 연가 8일 + 포상 3일(11일) <- 8/4~8/14

+ 사용 연가 : 15일
+ 사용 포상 휴가 : 8일

# 코딩 관련 글 or 사이트
웹프로그래밍 분야에서 배워야 할 개발 언어에 대해 이야기하겠습니다.

웹프로그밍은 보통 두가지 분야로 갈립니다.

Windows 서버와 Linux 서버입니다.

어떤 O/S 플랫폼을 주로 잡느냐에 따라 배우셔야할 내용은 어느 정도 갈립니다.

다음과 같이 정리하겠습니다.

공통
-----

필수 - HTML의 모든 것(HTML5 포함), CSS, Javascript

선택 - Javascript Framework Open Sources(보통 jQuery 등을 이야기), ActionScript(플래시 분야), Adobe Air

 

O/S별

------

※ Linux(리눅스) 서버

필수 - PHP, MySQL

선택적 필수 - JSP, JAVA 기초(이것을 원하는 클라이언트도 있으므로)

소양적 필수 - Linux 서버의 기본적 작동에 필요한 지식, 보안

 

※ Windows 서버

필수 - ASP.net(C# 또는 Visual Basic), ASP.net​은 언어가 아니라 기술을 칭하는 용어입니다. 그 기술에 사용하는 언어가 C# 등이 되겠습니다.

선택적 필수 - ASP(ASP.net이 나오기전에 주로 사용하던 언어입니다. 이것을 원하는 클라이언트도 있겠죠?)

소양적 필수 - Windows 서버의 기본적 작동에 필요한 지식, 보안

#codeing_test_link
1. 2022 카카오 신입 공채 1차 온라인 코딩테스트 - https://tech.kakao.com/2022/01/14/2022-kakao-recruitment-round-1/

# 컴퓨터 견적
본체 : 100~110(로아 144fps 풀옵 기준)
모니터 : 20 (27인치 144fps)
듀얼 모니터 암 : 10 (슬림형)
의자 : 20 (매쉬 or 패브릭 소재)
----------------------------------
150~160


# 프로젝트 주제
1. 스프링 쇼핑몰 프로젝트
장점 : 겉핥기식으로 하기 좋음. 스프링을 경험해 보며 웹프로그래밍 찍먹이 가능함.
단점 : 너무 방대한 부분을 다뤄야되서 현실성이 없을 거 같음. 둘이서 하기엔 분량이 너무 많아서 선우가 부담스러워 할 것 같음.

2. js 게임 만들기(테트리스,2048,지뢰찾기)
장점 : 비교적 수준에 맞는 첫 프로젝트라고 느껴짐
단점 : 너무 단순함, 말그대로 웹 프로젝트만 하는 느낌이라 뭔가 잘 이뤄지지는 않을듯?


### code server를 이용한 스프링 부트 공부 계획
1. 리눅스 서버 구축
2. code server를 그 서버에 설치
3. 공부

-----

서버 구축 방안
- aws
- 구글클라우드 플랫폼(무료를 이미 써버린듯)
- 네이버 클라우드
- 가비아 클라우드(정액제 있음)

----
<h3>코드스페이스 자바 설치 링크</h3>
https://docs.github.com/ko/codespaces/setting-up-your-project-for-codespaces/adding-a-dev-container-configuration/setting-up-your-java-project-for-codespaces