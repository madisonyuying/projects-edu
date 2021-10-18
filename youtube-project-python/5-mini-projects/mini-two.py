# number guesser projects
import random 
# importing random module 

# rand_num = random.randrange(-7,8) # randrange does not include 8 but if i used randint it would include 8 
guesses = 0

top_of_range = input("Type a number: ")
if top_of_range.isdigit():
    top_of_range = int(top_of_range)

    if top_of_range <= 0:
        print("Please type a number larger than zero next time.")
        quit()
else: 
    print("Please type a number next time.")
    quit()
    

rand_num = random.randint(0,top_of_range)
# print(rand_num) # printing a random number that was generated 


while True:
    guesses += 1 
    user_guess = input("Make a guess: ")
    if user_guess.isdigit():
        user_guess = int(user_guess)
    else: 
        print("Please type a number next time.")
        continue
    if user_guess == rand_num:
        print("You guessed correctly")
        break 
    elif user_guess > rand_num:
        print("You guessed above the number")
    elif user_guess < rand_num: 
        print("You guessed below the number")

print("You got it in", guesses, "guess(es)")
