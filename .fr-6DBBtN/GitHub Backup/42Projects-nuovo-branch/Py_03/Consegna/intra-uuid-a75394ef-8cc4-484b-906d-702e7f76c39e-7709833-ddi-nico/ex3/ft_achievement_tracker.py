#!/usr/bin/env python3

import random
from typing import ClassVar


class Player_Achievement_Cls:

    ALL_ACHIEVEMENTS: ClassVar[set[str]] = {
        "Crafting Genius", "Strategist", "World Savior", "Speed Runner",
        "Survivor", "Master Explorer", "Treasure Hunter", "Unstoppable",
        "First Steps", "Collector Supreme", "Untouchable", "Sharp Mind",
        "Boss Slayer"
    }

    def __init__(
        self, player: str, achievement: list[str] | None = None
    ) -> None:
        self.player: str = player
        self.achievement: set[str] = self.gen_player_achievements()

    def gen_player_achievements(self) -> set[str]:
        n = random.randint(0, len(self.ALL_ACHIEVEMENTS))
        if n < 2 or n > 5:
            n = random.randint(5, 9)
        player_set = set(random.sample(list(self.ALL_ACHIEVEMENTS), n))
        # random.sample richiede una sequesta ordinata, quindi convertiamo
        # l'insieme a lista
        return (player_set)

    @staticmethod
    def ft_achievement_tracker() -> None:
        print("=== Achievement Tracker System ===\n")

        # Generate achievement sets for a minimum of four different players
        players = ["Alice", "Bob", "Charlie", "Dylan"]
        player_objs: list[Player_Achievement_Cls] = []
        for player in players:
            player_obj = Player_Achievement_Cls(player)
            player_objs.append(player_obj)
            # count = len(player_obj.achievement)
            # total = len(Player_Achievement_Cls.ALL_ACHIEVEMENTS)
            # print(f"Unlocked ({count}/{total}): {player_obj.achievement}\n")
            print(f"Player {player_obj.player}: "
                  f"{player_obj.achievement}")

        # List Comprehension e' equivalente a
        # all_sets = []
        # for p in player_objs:
        #     all_sets.append(p.achievement)

        # Track unique achievements among all the players
        all_sets = [p.achievement for p in player_objs]
        all_dinstinct_achievements = set.union(*all_sets)

        print(f"\nAll distinct achievements: {all_dinstinct_achievements}\n")

        # Find achievements shared by all players
        common_achievements = set.intersection(*all_sets)
        print(f"Common achievements: {common_achievements}\n")

        # For each player, spot the achievements no one else has
        for i, p in enumerate(player_objs):
            all_sets2 = [
                q.achievement for j, q in enumerate(player_objs) if j != i
            ]
            all_others_union = set.union(*all_sets2) if all_sets2 else set()
            unique_to_player = p.achievement - all_others_union
            print(f"Only {p.player} has: {unique_to_player}")

        # For each player, list the missing achievements to have them all
        print("")
        for player in players:
            missing = Player_Achievement_Cls.ALL_ACHIEVEMENTS -\
                player_obj.achievement
            print(f"{player} is missing: {missing}")


if __name__ == "__main__":
    Player_Achievement_Cls.ft_achievement_tracker()
