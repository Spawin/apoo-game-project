# Liste des classes
- GameObject Abstract
  -
  - Personage Abstract
    -
    >life                                       max 100
    - Soldier
      > rage                                    max 100
    - Religious
      > blessing                                max 100
    - Druid
      > mana                                    max 100
    - Worker
      >
    - Trader

  - Item Abstract (un objet qui peux se retrouver dans un sac)
    -
    - Vial Abstract (Fiole ou encore boutielle) max par sac 6
      - Potion
      - Poison
    - TeleportKey (clé de téléportation)        max par sac 3
    - Armory Abstract ()                        max par sac 4
      - Weapon
        -
      - Shield
        -
    - Money                                     max par sac 9 999 999
  - Bag
    -
    Chaque type d'item aura un nombre limite qui peut être rangé dans le sac
  - NotMovableOject Abstract (objets non déplaçables)
    -
    Chaque objet va se présenter devant le joueur ^_^
    - Gate (la porte)
    - Table
    - Shelf (étagère du commerçant)
    - Chair
    - Bed
    - Carpet

- GameMap Abstract (Je me demande si j ne vais pas l'enlever... Peut être il sera abstract)
  -
  - House ()
    -

- Hall Abstract (Salle  )
  -
  - Room
  - Lounge (Le lieu de départ du joueur)

- Position
  -
  > hall Référence à la salle dans laquel l'objet se trouve.

- MyVector
  -
