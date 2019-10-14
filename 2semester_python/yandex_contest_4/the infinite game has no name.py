class Player:
    current_ready_method = 'ready'
    current_start_method = 'start'

    def ready(self, new_start_method, new_ready_method):
        setattr(self.__class__, new_ready_method, getattr(self, self.current_ready_method))
        delattr(self.__class__, self.current_ready_method)
        self.current_start_method = new_start_method
        self.current_ready_method = new_ready_method


def play(game):
    player = Player()
    player.game = game

    while True:
        getattr(game, player.current_start_method)(player)
