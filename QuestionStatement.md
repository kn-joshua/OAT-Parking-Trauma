# OAT Parking Trauma

## Problem Statement

Josh has a party planned with his friends at the OAT tonight. However, he leaves for party 10 minutes late. In order to compensate for his tardiness, he decides to get to the OAT on a stolen motorcycle. Sadly as he reaches the OAT, he realises that almost everyone had the same plan of partying at the OAT tonight and thus, the parking area is packed and he cannot park his bike anywhere. Josh is, however, a man of determination and decides that under no circumstances will he park somewhere far away from the OAT. Therefore, he decides to do a few illegal moves to reduce his walking effort. As his motorcycle takes more parking space than a bicycle, he decides to remove some cycles from their spots and throw them onto the road. Being lazy as well, he wants to remove the minimum number of cycles required such that his motorcyle can exactly fit in a spot. To do the following, Josh makes the following assumptions:

He decides to model the OAT Parking Area as $N$ x $H$ matrix $A$ where each block represents a parking spot which exactly fits for a bicycle. The bicycles are always parked from bottom to top. Formally speaking, an entity can only occupy $A[i][j]$ if and only if there is a entity on $A[i][j-1]$ (call it, the "Gravity Condition"). Thus, our parking area ends up looking similar to a histogram as shown below (for N=4 and H=8):

   ![Screenshot 2022-08-15 at 1 37 34 PM](https://user-images.githubusercontent.com/97837018/184599456-bdda91b9-5eab-4a57-863a-ea0e39233172.png)

Here, the red spots indicate taken parking spots while the black ones indicate free areas. Josh's motorbike is a $1$ x $K$ ( $K ≤ N$ ) entity that needs to be parked in a horizontal fashion such that the Gravity condition is satisfied on all cells where it is parked (i.e a bicycle is parked below every cell. Removing any bicycle from the top of any column (aka convert a red square to black) takes 1 unit of time, and Josh needs to get to the party as soon as possible.

Help Josh remove the minimum number of bicycles such that his motorbike can be parked. For example, if K=3 for the example given above: the optimum way to park the motorbike would be level the first three columns requiring a minimum of 2+4 = 6 units of time. 

![Screenshot 2022-08-15 at 3 20 59 PM](https://user-images.githubusercontent.com/97837018/184614790-a6e65c62-6803-410f-b81a-09d3842ad860.png) 

In the above picture, we convert the yellow cells to black requiring 6 units of time and then we park the bike as follows:

![Screenshot 2022-08-15 at 3 21 23 PM](https://user-images.githubusercontent.com/97837018/184614821-2c81cd12-5a06-44e6-8467-0fc86b15b0ba.png)


## Input

The first line contains one integer 𝑡 ( $1 ≤ 𝑡 ≤ 100$ ) — the number of test cases.

The first line of each test case consists of 3 integers : N, H and K ( $1 ≤ N ≤ 100$ , $1 ≤ H ≤ 100$ , $1 ≤ K ≤ N$ ) i.e the length of the parking spot, maximum height of the parking spot and the length of Josh's motorbike.

The second line consists of N integers h<sub>1</sub>, h<sub>2</sub>, ....., h<sub>N</sub> - the number of bicycles parked on the i<sup>th</sup> column, where 1 ≤ h<sub>i</sub> ≤ H for all $1 ≤ i ≤ N$

## Output

For each test case print your answer on a separate line — a single integer X denoting the minimum number of bicycles to be removed such that Josh's motorbike can be parked.

## Example

#### Input
3

4 8 3

4 6 2 8

6 7 3

1 2 3 1 1 1

7 8 5

1 2 3 4 5 1 1

#### Output

6

0

9

## Explanation

Test case 1 has already been explained in the example given in the problem statement

In test case 2, we already have a way to park (using the last 3 columns) hence no moves are needed. Thus, the time required is 0.

In test case 3, the optimum method would be to choose the last 5 columns requiring a total of 9 operations to level.
