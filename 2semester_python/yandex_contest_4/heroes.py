import json

MAX_VALUES = {
    "health": dict(Sorceress=50, Knight=100, Barbarian=120, Warlock=70),
    "defence": dict(Sorceress=42, Knight=170, Barbarian=150, Warlock=50),
    "attack": dict(Sorceress=90, Knight=150, Barbarian=180, Warlock=100),
    "mana": dict(Sorceress=180, Knight=0, Barbarian=0, Warlock=200)
}


def validate_and_update(armies):
    for army in armies.values():
        if 'mana' not in army:
            army['mana'] = 0
        for attr in ['health', 'attack', 'defence', 'mana']:
            max_value = MAX_VALUES[attr][army['race']]
            army[attr] = min(max_value, army[attr])


def is_dead(army):
    return army['health'] <= 0


def attack_to(to_defence, to_health, attack_power):
    if to_defence >= attack_power:
        return to_defence - attack_power, to_health
    return 0, to_health - (attack_power - to_defence)


def proceed_attack(army_from, army_to, power, attack_type):
    army_from[attack_type] -= power
    army_to['defence'], army_to['health'] = \
        attack_to(army_to['defence'], army_to['health'], power)

    if is_dead(army_to):
        army_to['experience'] += 5
    else:
        army_to['experience'] += 1

    army_from['experience'] += 1


def proceed_health_spell(army_from, army_to, power):
    army_from['mana'] -= power
    army_to['health'] = min(army_to['health'] + power,
                            MAX_VALUES['health'][army_from['race']])


def army_score(army):
    if is_dead(army):
        return 0
    return army['experience'] + army['defence'] * 2 + \
        army['attack'] * 3 + army['mana'] * 10


def run_events(steps, armies):
    for step in steps:
        action = step['action']
        army_from, army_to, power = \
            armies[step['id_from']], armies[step['id_to']], step['power']

        if is_dead(army_from) or is_dead(army_to):
            continue

        if action == 'attack':
            proceed_attack(army_from, army_to, power, 'attack')
        elif action == 'cast_health_spell':
            proceed_health_spell(army_from, army_to, power)
        elif action == 'cast_damage_spell':
            proceed_attack(army_from, army_to, power, 'mana')


def determine_winner(armies):
    score = {'Archibald': 0, 'Ronald': 0}

    for army in armies.values():
        score[army['lord']] += army_score(army)

    if score['Archibald'] < score['Ronald']:
        return 'Ronald'
    if score['Archibald'] == score['Ronald']:
        return 'unknown'
    return 'Archibald'


def main():
    json_data = json.loads(open('input.txt', mode='r').read())
    armies, steps = json_data['armies'], json_data['battle_steps']
    validate_and_update(armies)
    run_events(steps, armies)
    print(determine_winner(armies))


main()
