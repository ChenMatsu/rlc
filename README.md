# Reinforcement Learning Algorithm Library in C (RLC)

This library provides a collection of reinforcement learning algorithms implemented in C. It's designed to be flexible, efficient, and easy to use for various reinforcement learning tasks.

## Features

- Implementation of popular RL algorithms: Q-learning, DQN, PPO
- Flexible environment interface
- Utility functions for common RL operations
- Example environments for testing and learning

## Installation

To use this library, clone the repository and build it using the provided Makefile:

```bash
git clone https://github.com/ChenMatsu/rlc.git
cd rlc
make
```

## Usage

Here's a basic example of how to use the Q-learning algorithm with a grid world environment:

```c
#include "rlc.h"

int main() {
    Environment env;
    init_grid_world(&env);
    
    double learning_rate = 0.1;
    double discount_factor = 0.9;
    int max_episodes = 1000;
    
    q_learning(&env, learning_rate, discount_factor, max_episodes);
    
    return 0;
}
```

For more detailed examples, check the examples/ directory.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- Sutton and Barto's Reinforcement Learning: An Introduction

## Contact

If you have any questions or feedback, please open an issue on this repository.