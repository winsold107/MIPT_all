import json


def is_there_battle(game_list):
    if game_list["battle_steps"]:
        return True
    return False


def is_dead(unit_data):
    return unit_data["health"] == 0


def determine_points_winner(game_list):
    ar = 0
    ron = 0
    for unit_id, unit_data in game_list["armies"].items():
        if not is_dead(unit_data):
            if unit_data["lord"] == "Archibald":
                ar += int(unit_data["experience"]) + 2 * int(unit_data
                                                             ["defence"])
                ar += 3 * int(unit_data["attack"])
                if unit_data["race"] in ["Sorceress", "Warlock"]:
                    ar += 10 * int(unit_data["mana"])
            else:
                ron += int(unit_data["experience"]) + 2 * int(unit_data
                                                              ["defence"])
                ron += 3 * int(unit_data["attack"])
                if unit_data["race"] in ["Sorceress", "Warlock"]:
                    ron += 10 * int(unit_data["mana"])
    if ar > ron:
        return "Archibald"
    if ar < ron:
        return "Ronald"
    else:
        return "unknown"


# если is_there_battle = false, то сначала идем сюда
def determine_presence_winner(game_list):
    lords = set()
    for unit_id, unit_data in game_list["armies"].items():
        if not is_dead(unit_data):
            lords.add(unit_data["lord"])
    if lords == set():
        return "unknown"
    if "Archibald" not in lords:
        return "Ronald"
    if "Ronald" not in lords:
        return "Archibald"
    return "not_determined"


# могут ли напасть на мертвого,
# когда может не добавиться опыт атакуемому
# добавить опыт атакуемому
def attack(action, game_list):
    if1 = not is_dead(game_list["armies"][action["id_from"]])
    if2 = not is_dead(game_list["armies"][action["id_to"]])
    if if1 and if2:
        # уменьшаем количество атаки у атакующего
        at = int(game_list["armies"][action["id_from"]]["attack"])
        at = max(at - int(action["power"]), 0)
        game_list["armies"][action["id_from"]]["attack"] = at

        # смотрим, что с дефенс атакуемого
        game_list["armies"][action["id_to"]]["defence"] -= int(action["power"])
        if int(game_list["armies"][action["id_to"]]["defence"]) < 0:
            game_list["armies"][action["id_to"]]["health"] += \
                int(game_list["armies"][action["id_to"]]["defence"])
            game_list["armies"][action["id_to"]]["defence"] = 0
            if game_list["armies"][action["id_to"]]["health"] <= 0:
                game_list["armies"][action["id_to"]]["health"] = 0
                game_list["armies"][action["id_from"]]["experience"] += 5
            else:
                game_list["armies"][action["id_from"]]["experience"] += 1
    elif not is_dead(game_list["armies"][action["id_to"]]):
        game_list["armies"][action["id_to"]]["experience"] += 1


# вычесть ману у атакующего
def damage_spell(action, game_list):
    if1 = not is_dead(game_list["armies"][action["id_from"]])
    if2 = game_list["armies"][action["id_from"]]["mana"] != 0
    if3 = not is_dead(game_list["armies"][action["id_to"]])
    if if1 and if2 and if3:
        game_list["armies"][action["id_to"]]["defence"] -= int(action["power"])
        if int(game_list["armies"][action["id_to"]]["defence"]) < 0:
            b = game_list["armies"][action["id_to"]]["defence"]
            game_list["armies"][action["id_to"]]["health"] += int(b)
            game_list["armies"][action["id_to"]]["defence"] = 0
            if game_list["armies"][action["id_to"]]["health"] <= 0:
                game_list["armies"][action["id_to"]]["health"] = 0
                game_list["armies"][action["id_from"]]["experience"] += 5
            else:
                game_list["armies"][action["id_from"]]["experience"] += 1

        k = game_list["armies"][action["id_from"]]["mana"]
        game_list["armies"][action["id_from"]]["mana"] = \
            (max(0, k - action["power"]))
    elif not is_dead(game_list["armies"][action["id_to"]]):
        game_list["armies"][action["id_to"]]["experience"] += 1


# сколько mana тратит заклинание и начисляется ли за него опыт
def health_spell(action, game_list):
    if1 = not is_dead(game_list["armies"][action["id_from"]])
    if2 = game_list["armies"][action["id_from"]]["mana"] != 0
    if3 = not is_dead(game_list["armies"][action["id_to"]])
    if if1 and if2 and if3:
        a = game_list["armies"][action["id_to"]]["health"]
        if game_list["armies"][action["id_to"]]["race"] == "Barbarian":
            game_list["armies"][action["id_to"]]["health"] = \
                min(120, a + action["power"])

        elif game_list["armies"][action["id_to"]]["race"] == "Sorceress":
            game_list["armies"][action["id_to"]]["health"] = \
                min(50, a + action["power"])

        elif game_list["armies"][action["id_to"]]["race"] == "Knight":
            game_list["armies"][action["id_to"]]["health"] = \
                min(100, a + action["power"])

        elif game_list["armies"][action["id_to"]]["race"] == "Warlock":
            game_list["armies"][action["id_to"]]["health"] = \
                min(70, a + action["power"])

        game_list["armies"][action["id_from"]]["experience"] += 1

        a5 = game_list["armies"][action["id_from"]]["mana"]
        game_list["armies"][action["id_from"]]["mana"] \
            = max(0, a5 - action["power"])


def check_sorceress(data):
    data["health"] = min(50, int(data["health"]))
    data["defence"] = min(42, int(data["defence"]))
    data["attack"] = min(90, int(data["attack"]))
    data["mana"] = min(200, int(data["mana"]))


def check_knight(data):
    data["health"] = min(100, int(data["health"]))
    data["defence"] = min(170, int(data["defence"]))
    data["attack"] = min(150, int(data["attack"]))


def check_barbarian(data):
    data["health"] = min(120, int(data["health"]))
    data["defence"] = min(150, int(data["defence"]))
    data["attack"] = min(180, int(data["attack"]))


def check_warlock(data):
    data["health"] = min(70, int(data["health"]))
    data["defence"] = min(50, int(data["defence"]))
    data["attack"] = min(100, int(data["attack"]))
    data["mana"] = min(180, int(data["mana"]))


def check_values(game_list):
    for unit_id, unit_data in game_list["armies"].items():
        if unit_data["race"] == "Sorceress":
            check_sorceress(unit_data)
        if unit_data["race"] == "Knight":
            check_knight(unit_data)
        if unit_data["race"] == "Barbarian":
            check_barbarian(unit_data)
        if unit_data["race"] == "Warlock":
            check_warlock(unit_data)


a = input()
game_list = json.loads(a)

is_winner_known = False

check_values(game_list)

if not is_there_battle(game_list):
    presence_winner = determine_presence_winner(game_list)
    if presence_winner != "not_determined":
        print(presence_winner)
        is_winner_known = True
    else:
        print(determine_points_winner(game_list))
        is_winner_known = True
else:
    for actions in game_list["battle_steps"]:
        # print(actions)
        if actions["action"] == "attack":
            attack(actions, game_list)
        elif actions["action"] == "cast_damage_spell":
            damage_spell(actions, game_list)
        elif actions["action"] == "cast_health_spell":
            health_spell(actions, game_list)

if not is_winner_known:
    presence_winner = determine_presence_winner(game_list)
    if presence_winner != "not_determined":
        print(presence_winner)
    else:
        print(determine_points_winner(game_list))
