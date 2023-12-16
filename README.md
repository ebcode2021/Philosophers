# philosophers

## Introduction

<img src="https://commons.wikimedia.org/wiki/File:An_illustration_of_the_dining_philosophers_problem.png"/>

"식사하는 철학자" 문제는 병렬 컴퓨팅 환경에서 **자원 공유와 데드락 회피**의 어려움을 보여주는 고전적인 동기화 및 병렬 처리 문제다. \
C 언어를 사용하여 멀티 스레드 및 멀티 프로세스 프로그래밍에 대한 학습을 진행하며 코드를 작성했다.

"The Dining Philosophers Problem" is a classical synchronization and parallel processing issue that illustrates challenges in **resource sharing and deadlock avoidance** in a parallel computing environment. \
This project is a training to multi-treads/multi-process programming using C.

## Directory Overview

**philo** : multi-threading with mutex synchronization. \
**philo_bonus** : multi-process programming with semaphore synchronization.

## Usage

**- Build**

```
$ cd philo
$ make
```

**- Execution**

```
$ ./philo [number_of_philosophers] [time_to_die] [time_to_eat]
	[time_to_sleep](number_of_times_each_philosopher_must_eat)

$ ./philo_bonus [number_of_philosophers] [time_to_die] [time_to_eat]
	[time_to_sleep](number_of_times_each_philosopher_must_eat)
```

**- Help**

```
$ ./philo --help
-------------------------------------------------------------

║▌│█║▌│ █║▌│█│║▌█║▌│ █│█║▌│ ██│║▌║
         This is Manual for you...∧,,,∧
                               (  ̳• · • ̳)
                                 /    /r 🎁

| First             : number_of_philosophers
| Second            : time_to_die
| Third             : time_to_eat
| Fourth            : time_to_sleep
| Fifth(optional)   : number_of_times_each_philosopher_must_eat

-------------------------------------------------------------
```

**- Example** \
**Case 1** : All philosophers eat a fixed number of times. \
`./philo 5 800 200 200 3`

**Case 2**: One philosopher starves to death. \
`./philo 2 400 200 210`

**Case 3** : All philosophers keep eating. \
`./philo 200 800 200 200`

![case1](https://github.com/ebcode2021/philosophers/assets/84271971/059c73be-6b4f-468a-aa2c-e13140b2d99d)

## Code Flow

<!--// 여기에 코드 플로우-->

## Key Concepts

1. Thread vs Process

-   Thread : 할당받은 자원을 이용하는 **실행 단위**
-   Process : 운영체제로부터 자원을 **할당받는 단위**

2. Data Race \
   read와 write가 동시에 일어나는 상황

3. DeadLock \
   교착상태\
   두 개 이상의 프로세스나 스레드가 서로 상대방의 작업이 끝나기를 기다리며 무한히 대기하는 상태
     <details>
     <summary> DeadLock의 4가지 필요조건 </summary>

    - 상호배타(Mutual Exclusion): 자원은 한 번에 하나의 프로세스나 스레드만 사용
    - 점유와 대기(Hold and Wait) : 적어도 하나의 자원을 가진 채로 다른 자원을 대기
    - 비선점(No Preemption) : 이미 할당된 자원을 강제로 빼앗을 수 없다.
    - 환형 대기(Circular Wait) : 순환 형태로 자원을 대기
          </details>

4. multi-thread vs multi-process

-   multi-thread
    -   적은 메모리 공간을 사용한다. Context Switching이 빠르다.
    -   하나의 스레드 장애가 전체 스레드를 종료시킬 위험이 있다.
    -   동기화에 조심해야 한다.
-   multi-process
    -   독립적인 구조를 갖고 있으며 안정적이다.
    -   작업량이 많을 경우, 시스템 콜이 증가하면서 Context Switching이 많아진다.
    -   이로인한 오버헤드가 발생할 수 있으며, 성능이 저하할 수 있다.

5. Mutex \
   공유된 자원 or 임계 영역에 **하나**의 thread나 process가 접근하는 것을 막는다. \
   Lock / Unlock 개념으로, **동기화 대상이 오직 1개**다.

6. Semaphore \
   공유된 자원 or 임계 영역에 **다수**의 thread나 process가 접근하는 것을 막는다.
   Wait / Post 개념으로 **동기화 대상이 N개**다.
