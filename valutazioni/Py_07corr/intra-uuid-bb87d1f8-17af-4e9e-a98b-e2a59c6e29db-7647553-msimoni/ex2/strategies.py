import abc
from ex0.creatures import Creature
import ex1


class InvalidStrategyError(Exception):
    ...


class BattleStrategy(abc.ABC):

    @abc.abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        ...

    @abc.abstractmethod
    def act(self, creature: Creature) -> None:
        ...


class NormalStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, Creature)

    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise InvalidStrategyError(f"Invalid Creature")
        print(creature.attack())


class AggressiveStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, ex1.TransformCapability)

    def act(self, creature: Creature) -> None:
        if not isinstance(creature, ex1.TransformCapability):
            raise InvalidStrategyError(
                f"Invalid Creature '{creature.name}' "
                "for this aggressive strategy"
            )
        print(creature.transform())
        print(creature.attack())
        print(creature.revert())


class DefensiveStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, ex1.HealCapability)

    def act(self, creature: Creature) -> None:
        if not isinstance(creature, ex1.HealCapability):
            raise InvalidStrategyError(
                f"Invalid Creature '{creature.name}' "
                "for this defensive strategy"
            )
        print(creature.attack())
        print(creature.heal())
