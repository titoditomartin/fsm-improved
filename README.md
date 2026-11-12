# FSM of a Microwave

Finite state machine (FSM) is a term used by programmers, mathematicians, engineers and other professionals to describe a mathematical model for any system that has a limited number of conditional states of being. A finite state machine for a microwave would have a limited number of states that represent the different actions and modes of the device, and the transitions between those states would be triggered by specific inputs or events. In the FSM that I created, the input would be 2-bit with 3 states. The first state **(00)** is where the microwave door is open and the timer hasn't been started. The second state **(01)** is when the microwave door is closed and the timer hasn't been started. The third state **(10)** is when the microwave has started cooking with the door closed and the timer started.

# States

1.  Door Open (00)
2.  Door Closed (01)
3.  Cooking (10)


# Inputs
The inputs would be a 2-bit input :

  1. D (0/1) = Door open (0) / door close (1)
  2. T (0/1) = Timer hasn't start (0) / timer start (1)





## FSM Diagram
![WhatsApp Image 2023-01-22 at 22 47 39](https://user-images.githubusercontent.com/114073725/213926847-76edb368-3e42-40f3-babf-c3b3875af720.jpeg)





## Truth Table
![WhatsApp Image 2023-01-22 at 23 11 36](https://user-images.githubusercontent.com/114073725/213926849-f0642e24-0fcf-40de-a538-60a2f1f22b13.jpeg)




## Karnaugh map
S0
- ![s0](https://user-images.githubusercontent.com/114073725/213926876-752c1b60-e139-4ac3-851c-7bfdd0d1a1a6.png)
- ![s0 kmap](https://user-images.githubusercontent.com/114073725/213926879-465b7013-1a71-4268-bbc2-67fd2be5ccbc.png)

S1
- ![s1](https://user-images.githubusercontent.com/114073725/213926892-55b8af9b-0644-4c79-8ae0-84255506166c.png)
- ![s1 kmap](https://user-images.githubusercontent.com/114073725/213926902-e1cb4285-47c0-4558-b616-c31654553138.png)

Output
- ![output](https://user-images.githubusercontent.com/114073725/213926913-43133564-77f8-4e70-9679-83c69b359313.png)
- ![output kmap](https://user-images.githubusercontent.com/114073725/213926918-a6dc5212-863a-490a-b4e8-5a0cb58beb54.png)

## Visualization
  ### First State
- <img width="351" alt="image" src="https://user-images.githubusercontent.com/114073725/213934622-0c4c3b10-dc4f-411a-b1e5-3c3741d3577e.png">
- This image shows the starting state, where the door is open and timer hasn't started.

  ### Second State
- <img width="347" alt="image" src="https://user-images.githubusercontent.com/114073725/213934707-93635734-8102-452e-9c06-66271ad54ae8.png">
- This image shows the second state, where the door is closed but timer hasn't started.

  ### Third State
- ![screen-capture (2) (1)](https://user-images.githubusercontent.com/114073725/213936396-db675189-c2d4-4d01-992d-2410e66373ca.gif)
- This is a demonstration of the visualization from the starting state


