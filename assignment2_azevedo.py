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


class BoardGame():
    def __init__(self, title, genre, players, current_turn):
        super().__init__(title, genre)
        self.players = players
        self.current_turn = current_turn

    def play(self):
        pass

    def next_turn(self):
        pass

    def __str__(self):
        return {f""}

class VideoGame():
    def __init__(self, title, genre, platform, progress):
        super().__init__(title, genre)
        self.platform = platform
        self.progress = progress

    def play(self):
        pass
    
    def save_progress(self, progress):
        pass

    def __str__(self):
        return {f""}


# =============================================================================
    
# TODO: write the Node and GameLinkedList class here


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
