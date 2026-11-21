# Group members: 

# 1. Check the provided class diagrams
# 2. Finish the 5 required classes
# 3. Use the provided test code to test your work

# =============================================================================
# import
from abc import ABC, abstractmethod

# TODO: write the 3 game classes here

class Game(ABC):
    def __init__(self, title, genre):
        self.title = title
        self.genre = genre

    @abstractmethod
    def play(self):
        pass


class BoardGame(Game):
    def __init__(self, title, genre, players):
        super().__init__(title, genre)
        self.players = players
        self.current_turn = 0

    def play(self):
        print(f'Playing {self.title} with {self.players} players...')

    def next_turn(self):
        self.current_turn += 1

    def __str__(self):
        return (f'BoardGame({self.title})')

class VideoGame(Game):
    def __init__(self, title, genre, platform):
        super().__init__(title, genre)
        self.platform = platform
        self.progress = 0

    def play(self):
        print(f'Playing {self.title} on {self.platform}...')
    
    def save_progress(self, progress):
        self.progress = progress

    def __str__(self):
        return (f'VideoGame({self.title})')


# =============================================================================
    
# TODO: write the Node and GameLinkedList class here

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class GameLinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def append(self, game):
        node = Node(game)
        if self.head is None:
            self.head = node
        else:
            curr = self.head
            while curr.next is not None:
                curr = curr.next
            curr.next = node
        self.size += 1  

    def remove_first(self):
        if self.head is None:
            return None
        removed = self.head.data
        self.head = self.head.next
        self.size -= 1
        return removed

    def count_games(self):
        video_games = 0
        board_games = 0
        curr = self.head
        while curr is not None:
            if isinstance(curr.data, VideoGame):
                video_games += 1
            elif isinstance(curr.data, BoardGame):
                board_games += 1
            curr = curr.next
        return (video_games, board_games)

    def __str__(self):
        if self.head is None:
            return 'Empty list'
        out = ''
        curr = self.head
        while curr is not None:
            out += str(curr.data)
            if curr.next is not None:
                out += ' -> '
            curr = curr.next
        return out

# =============================================================================

# == DO NOT MODIFY ANY CODE BELOW THIS LINE ==

def test_code():
    # Test VideoGame class
    game1 = VideoGame("Tetris", "Strategy", "PC")
    game1.play()
    game1.save_progress(2)
    print(game1, 'Progress:', game1.progress, '\n')

    # Test BoardGame class    
    game2 = BoardGame("Chess", "Sports", 2)
    game2.play()
    game2.next_turn()
    print(game2, 'Current Turn:', game2.current_turn, '\n')

    # Create an empty linked list
    game_list = GameLinkedList()
    print(game_list) # Empty list

    # Append some games
    game_list.append(game1)
    game_list.append(game2)
    game_list.append(VideoGame("Fires", "Racing", "PC"))
    game_list.append(VideoGame("Flyers", "Sports", "iPad"))
    game_list.append(BoardGame("World", "Party", 4))
    game_list.append(VideoGame("Farmers", "Strategy", "PC"))
    print("Initial list:")
    print(game_list)

    for _ in range(game_list.size + 1):
        # Count video games and board games
        video_games_count, board_games_count = game_list.count_games()
        print(f"\nNumber of video games: {video_games_count}, board game: {board_games_count}" +
              f", Total number of games: {game_list.size}")
        # Remove and return the first game
        removed_game = game_list.remove_first()
        print("Removed game:", removed_game)
        print("List after removing the first game:")
        print(game_list)

if __name__ == "__main__":
    test_code()
