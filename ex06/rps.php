<?php

$win = "Congratulations! You won! The computer chose";
$lose = "Sorry, you lost. The computer chose";
$draw = "It's a draw. The computer chose";

$choices = array("rock", "paper", "scissors");

echo "Choose rock, paper, or scissors: ";
$line = (string)fgets(STDIN);
// $line = (string)fopen(STDIN, "r");
// $line = (string)fopen("php://stdin", "r");
$line = strtolower($line);
$line = trim($line);

if ($line == "" || !($line == "rock" || $line == "paper" || $line == "scissors")) {
	printf("\n[Error] You must choose rock, paper, or scissors.\n");
} else {
	$computer = $choices[rand(0, 2)];
	if ($line == $computer) {
		printf("%s %s.\n", $draw, $computer);
	} elseif ($line == "rock" && $computer == "scissors") {
		printf("%s %s.\n", $win, $computer);
	} elseif ($line == "paper" && $computer == "rock") {
		printf("%s %s.\n", $win, $computer);
	} elseif ($line == "scissors" && $computer == "paper") {
		printf("%s %s.\n", $win, $computer);
	} else {
		printf("%s %s.\n", $lose, $computer);
	}
}

?>
