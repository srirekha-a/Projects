import random
def game(num_digits):
    #generate list of random integers of length num_digits
    listnum = [random.randint(0,9) for n in range(num_digits)]
    count=0
    while True:
        count+=1
        print("Guess:" + str(count))
        print("Please guess a " + str(num_digits) + "-digit number:")
        # transform input string (e.g. "1234") to list of integers (e.g. [1,2,3,4])
        guess = [int(i) for i in str(input())]
        if guess == listnum:
            print("You won:)")
            print("It took you "+str(count)+" guess(es).")
            break
        else:
            cow=0
            bull=0
            for x in range(0,num_digits):
                if guess[x]==listnum[x]:
                    cow += 1
                elif guess[x] in listnum: # look if digit is somewhere else in the solution key (might already be a cow)
                    bull += 1
        print("Cows:"+str(cow)+" Bulls:"+str(bull))
        print("------------------------------")
        if count == 15:
            print("You lost:(")
            print("Solution key = " + str(listnum))
            print("Wanna play again?\nEnter y to play and n to exit!")
            ch=input()
            if ch=="y":
                print("Which Level would you like to play?\n Level-1 or Level-2 or Level-3 or Level-4")
                l=int(input())
                if l==1:
                    print("New Game starts!")
                    game(1)
                elif l==2:
                    print("New Game starts!")
                    game(2)
                elif l==3:
                    print("New Game starts!")
                    game(3)
                elif l==4:
                    print("New Game starts!")
                    game(4)
                else:
                    print("Sorry, That was an invalid level!\n Try Again!")
                    break
            else:
                break            
game(2)
