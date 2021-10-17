print("Welcome to my reptile quiz")

playing = input("Do you want to play the quiz? ")

if playing.lower() != "yes":
    quit()
print("Okay! Let's play!")
score = 0 

answerOne = input("How many types of scales do snakes have? ")
if answerOne.lower() == "three" :
    print("Correct!")
    score+=1 
else: 
    print("incorrect!")

answerTwo = input("Are there venomous of poisonous snakes? ")
if answerTwo.lower() == "venomous":
    print("Correct!")
    score+=1
else: 
    print("incorrect!")
answerThree = input("Are corn snakes rat snakes? ")
if answerThree.lower() == "yes" :
    print("Correct!")
    score+=1 
else: 
    print("incorrect!")

print("You got " +  str(score) + " questions correct!" )
print("You got " +  str((score/3)*100) + " %!" )