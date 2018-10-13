#imports pygame in to the program for use of its 
import pygame, sys
#brings all of the local pygames files to the program
from pygame.locals import *


#Intializes the pygame mixer function in which allows the programmer
#to add background music to their program
pygame.mixer.pre_init(22050,-16,2,4096)
pygame.mixer.init()

#initalizes the pygame its self
pygame.init()
#allows the programmer to access different fonts
pygame.font.init()


font_path = "./fonts/newfont.ttf"

#Defines all the color values

max_w = 800
max_h = 600
red = (255, 0, 0)
white = 255,255,255


green = (0,255,0)
blue = (0,0,255)
darkBlue = (0,0,128)

black = (0,0,0)
pink = (255,200,200)


font = pygame.font.SysFont('monospace', 12)

#defines the pygame window
screen = pygame.display.set_mode((max_w,max_h))

#Plays the background music and loops it until program is interrupted
pygame.mixer.music.load("Believe.mp3")
pygame.mixer.music.set_volume(0.5)

#(-1) means loop the song forever

pygame.mixer.music.play(-1)

class Cell:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.length = 130
        self.color = white
    def draw_cell(self):
        pygame.draw.rect(screen, self.color, (self.x,self.y,self.length, self.length), 2)
    def draw_O(self):
        pygame.draw.circle(screen, black, (self.x + 65, self.y + 65), 65, 5)
    def draw_X(self):
        pygame.draw.line(screen, black, (self.x, self.y), (self.x + 130, self.y+130), 10)
        pygame.draw.line(screen, black, (self.x, self.y+130), (self.x+130, self.y), 10)
        

board = [ [' ', ' ', ' '], [' ', ' ', ' '], [' ', ' ', ' '] ]

#Check if player wins
def check_win(turn, run):
    if board[0][0] == turn and board[0][1] == turn and board[0][2] == turn:
        print(turn, ' is the winner')
        run = False
    elif board[1][0] == turn and board[1][1] == turn and board[1][2] == turn:
        print(turn, ' is the winner')
        run = False
    elif board[2][0] == turn and board[2][1] == turn and board[2][2] == turn:
        print(turn, ' is the winner')
        run = False
    elif board[0][0] == turn and board[1][0] == turn and board[2][0] == turn:
        print(turn, ' is the winner')
        run = False
    elif board[0][1] == turn and board[1][1] == turn and board[2][1] == turn:
        print(turn, ' is the winner')
        run = False
    elif board[0][2] == turn and board[1][2] == turn and board[2][2] == turn:
        print(turn, ' is the winner')
        run = False
    elif board[0][0] == turn and board[1][1] == turn and board[2][2] == turn:
        print(turn, ' is the winner')
        run = False
    elif board[0][2] == turn and board[1][1] == turn and board[2][0] == turn:
        print(turn, ' is the winner')
        run = False
    else:
        run = True
    return run


#player turns
turn = 'x'



#Keeps the program running
run = True

#create an object from the Cell class
rect = Cell(135, 115)
rect2 = Cell(315, 115)
rect3 = Cell(505, 115)
rect4 = Cell(135, 255)
rect5 = Cell(315, 255)
rect6 = Cell(505, 255)
rect7 = Cell(135, 392)
rect8 = Cell(315, 392)
rect9 = Cell(505, 392)



#Program will conti until a winner is declared
conti = 0
while run:
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()

     
    #program windows background has been set to white
    screen.fill(white)

    #The program window's caption has been set to TIC-TAC-TOE
    pygame.display.set_caption("TIC-TAC-TOE")
    

    print(turn)
    
    if pygame.key.get_pressed()[pygame.K_q] != 0:
        if board[0][0] == ' ':
            board[0][0] = turn
           
            run = check_win(turn,run)               
            turn = 'o' if turn == 'x' else 'x'
            
    elif pygame.key.get_pressed()[pygame.K_w] != 0:
        if board[0][1] == ' ':
            board[0][1] = turn
           
            run = check_win(turn,run)            
            turn = 'o' if turn == 'x' else 'x'
            
    elif pygame.key.get_pressed()[pygame.K_e] != 0:
         if board[0][2] == ' ':
             board[0][2] = turn
           
             run = check_win(turn,run)               
             turn = 'o' if turn == 'x' else 'x'
            
    elif pygame.key.get_pressed()[pygame.K_a] != 0:
         if board[1][0] == ' ':
             board[1][0] = turn
           
             run = check_win(turn,run)               
             turn = 'o' if turn == 'x' else 'x'
            
    elif pygame.key.get_pressed()[pygame.K_s] != 0:
         if board[1][1] == ' ':
             board[1][1] = turn
           
             run = check_win(turn,run)               
             turn = 'o' if turn == 'x' else 'x'
            

    elif pygame.key.get_pressed()[pygame.K_d] != 0:
        if board[1][2] == ' ':
            board[1][2] = turn
           
            run = check_win(turn,run)               
            turn = 'o' if turn == 'x' else 'x'
            
    elif pygame.key.get_pressed()[pygame.K_z] != 0:

        if board[2][0] == ' ':
            board[2][0] = turn
           
            run = check_win(turn,run) 
            turn = 'o' if turn == 'x' else 'x'

            
        
        
    elif pygame.key.get_pressed()[pygame.K_x] != 0:
        if board[2][1] == ' ':
            board[2][1] = turn
           
            run = check_win(turn,run) 
            turn = 'o' if turn == 'x' else 'x'
            
    elif pygame.key.get_pressed()[pygame.K_c] != 0:
        if board[2][2] == ' ':
            board[2][2] = turn
            run = check_win(turn,run) 
                
            turn = 'o' if turn == 'x' else 'x'
            
 
    #if pygane.key.get_pressed() != 0:
          
    pygame.draw.line(screen, red, (285,100), (285,530), 10)
    pygame.draw.line(screen, red, (475,100), (475,530), 10)
    pygame.draw.line(screen, red, (100,385), (650,385), 10)
    pygame.draw.line(screen, red, (100,250), (650,250), 10)
    
    #check python created least 'board' to see it has been changed to 'x' or 'o' if it has
    #the program will draw an 'X' or 'O' in the pygame window
    #based on the corresponding letter
    if board[0][0] == 'x':
        rect.draw_X()
    elif board[0][0]=='o':
        rect.draw_O()
    if board[0][1] == 'x':
        rect2.draw_X()
    elif board[0][1]=='o':
        rect2.draw_O()
    if board[0][2] == 'x':
        rect3.draw_X()
    elif board[0][2]=='o':
        rect3.draw_O()
    if board[1][0] == 'x':
        rect4.draw_X()
    elif board[1][0]=='o':
        rect4.draw_O()
    if board[1][1] == 'x':
        rect5.draw_X()
    elif board[1][1]=='o':
        rect5.draw_O()
    if board[1][2] == 'x':
        rect6.draw_X()
    elif board[1][2]=='o':
        rect6.draw_O()
    if board[2][0] == 'x':
        rect7.draw_X()
    elif board[2][0]=='o':
        rect7.draw_O()
    if board[2][1] == 'x':
        rect8.draw_X()
    elif board[2][1]=='o':
        rect8.draw_O()
    if board[2][2] == 'x':
        rect9.draw_X()
    elif board[2][2]=='o':
        rect9.draw_O()

#This program will check all the possibilities of winning and then declare the winner every loop
#if there is no winner the looop continues to run.
#If there is no winner and the board has been completely filled then the board will reset itself
#and it will go back to the first player('X') to start the game 
    if board[0][0] != ' ' and board[0][1] != ' ' and board[0][2] != ' ' and board[1][0] != ' ' and board[1][1] != ' ' and board[1][2] != ' ' and board[2][0] != ' ' and board[2][1] != ' ' and board[2][2] != ' ':
        board = [ [' ', ' ', ' '], [' ', ' ', ' '], [' ', ' ', ' '] ]
        turn = 'x'

    pygame.display.flip()
pygame.quit()    
    
