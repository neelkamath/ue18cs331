# UE18CS331

These are my assignments for [PESU](https://pes.edu/)'s UE18CS331 (Generic Programming) course. If you're using Windows, use WSL to run the commands.

## Installation

1. Install either g++ or [Docker](https://docs.docker.com/get-docker/).
1. Clone the repo using one of the following methods:
    - SSH: `git clone git@github.com:neelkamath/ue18cs331.git`
    - HTTPS: `git clone https://github.com/neelkamath/ue18cs331.git`
1. If you're using Docker, run `cd ue18cs331 && docker build -t ue18cs331 .`

## Usage

1. If you're using Docker instead of a local g++ installation, run:
    ```
    docker run --rm -it --mount type=bind,src=$PWD,dst=/app ue18cs331
    ```
1. Run the programs in the `src` directory using C++20. For example:
    ```
    cd src/unit-2/assignment-1/question-2 && g++ -std=c++2a *.cpp && ./a.out
    ```
1. If you're using Docker, and have finished running the programs, run `exit`.

## Contributing

The `src` directory uses the format `unit-<UNIT_NUMBER>/assignment-<ASSIGNMENT_NUMBER>/question-<QUESTION_NUMBER>` (e.g., `unit-1/assignment-1/question-1`). Each question must have a `main.cpp` file with the question at the top of the file in a comment.

## License

This project is under the [MIT License](LICENSE).
