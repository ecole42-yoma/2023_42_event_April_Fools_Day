<?php

$win = "Congratulations! You won! The computer chose ";
$lose = "Sorry, you lost. The computer chose ";
$draw = "It's a draw. The computer chose ";

$choices = array("rock.", "paper.", "scissors.");

echo "Choose rock, paper, or scissors: ";
$line = (string)fgets(STDIN);
$line = strtolower($line);
$line = trim($line);

if ($line == "" || $line == "rock" || $line == "paper" || $line == "scissors") {
	echo "You must choose rock, paper, or scissors."
}else{
	$computer = $choices[rnad(0, 2)];
	// check for win, lose, or draw
	if ($line == "rock" && $computer == "scissors.") {
		echo $win $computer;
	} elseif ($line == "paper" && $computer == "rock.") {
		echo $win $computer;
	} elseif ($line == "scissors" && $computer == "paper.") {
		echo $win $computer;
	} elseif ($line == $computer) {
		echo $draw $computer;
	} else {
		echo $lose $computer;
	}
}


?>
