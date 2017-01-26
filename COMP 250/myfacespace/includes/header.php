<?php

session_start();

if (!isset($title))
    $title = 'MyFaceSpace';
?>

<!DOCTYPE html>
<html>

<head>
    <title><?php echo $title ?></title>

    <meta charset="UTF-8">
    <link href="https://cdnjs.cloudflare.com/ajax/libs/pure/0.6.0/pure-min.css" rel="stylesheet">
    <link href="css/base.css" rel="stylesheet">

    <script>
        function removeFriend(i) {
            if (confirm("Are you sure you want to remove " + i + "?"))
                location = "remove_friend_db.php?username=" + i;
        }

        document.addEventListener("DOMContentLoaded", function (event) {
            var friends = document.getElementsByClassName("removeButton");

            for (var i = 0; i < friends.length; i++) {
                friends[i].addEventListener("click", function () {
                    removeFriend(this.id)
                }, false);
            }
        });

        function addFriend(i) {

            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById(i).style.display = "none";
                }
            };
            xhttp.open("GET", "add_friend_db.php?username=" + i, true);
            xhttp.send();
        }

        document.addEventListener("DOMContentLoaded", function (event) {
            var friends = document.getElementsByClassName("addButton");

            for (var i = 0; i < friends.length; i++) {
                friends[i].addEventListener("click", function () {
                    addFriend(this.id)
                }, false);
            }
        });

    </script>

</head>

<body>

<nav class="navbar">
    <h1>MyFaceSpace</h1>
    <a href="index.php">Home</a>
    <a href="add_friends.php">Add Friends</a>
    <a href="edit_account.php">Edit Account</a>
    <?php if ($_SESSION['login'] === true) {
        echo "<a href='logout.php'>Logout</a>";
    } else {
        echo "<a href='login.php'>Login</a>";
    }
    ?>
</nav>

<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

?>

<div class="container">
