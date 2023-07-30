import random

def word_guessing_game():
    print("What is your name?")
    name = input("Good Luck! ")

    words = ["rainbow", "computer", "science", "programming", "python"]
    word = random.choice(words)
    print("Guess the characters")
    guesses = '_' * len(word)
    turns = 12

    while turns > 0:
        failed = 0

        for i in range(len(word)):
            if word[i] in guesses:
                print(word[i], end=" ")
            else:
                print("_", end=" ")
                failed += 1

        if failed == 0:
            print("\nYou win")
            print("The word is: ", word)
            break

        guess = input("\nguess a character: ")
        guesses += guess

        if guess not in word:
            turns -= 1
            print("Wrong")
            print(f"You have {turns} more turns")

            if turns == 0:
                print("You Lose")

word_guessing_game()