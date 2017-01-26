<?php

$title = 'Index | MyFaceSpace';
include('includes/header.php');

if (!isset($_SESSION['login']) || $_SESSION['login'] !== true) {
    ?>

    <h1>You must be logged in to access this page</h1>
    <a href="login.php">Login</a>

    <?php
} else {

    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        $search = $_POST['search'];
    }

    ?>

    <h1>Add a friend</h1>

    <form action="add_friends.php" method="POST">
        <input type="text" name="search" required>
        <button>Search</button>
    </form>

    <?php if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        echo "<br>Listing results for '$search' <hr>";

        require('date_util.php');
        require('database.php');
        $mysqli = ConnectToDatabase();

        $ps = $mysqli->prepare('SELECT * FROM Users WHERE name LIKE ? ORDER BY name');
        $query = '%' . $search . '%';
        $ps->bind_param(
            's',
            $query

        );
        $ps->execute();
        $searchResult = $ps->get_result();

        $ps = $mysqli->prepare("SELECT username1 FROM Friends WHERE username2 = ? UNION
SELECT username2 FROM Friends WHERE username1 = ?");
        $ps->bind_param(
            'ss',
            $_SESSION['username'],
            $_SESSION['username']
        );
        $ps->execute();

        $result = $ps->get_result();

        $friends = array();

        while ($row = $result->fetch_assoc()) {
            if (isset($row['username1'])) {
                $friends[] = $row['username1'];
            }

            if (isset($row['username2'])) {
                $friends[] = $row['username2'];
            }
        }

        while ($row = $searchResult->fetch_assoc()) {
            if ($row['username'] === $_SESSION['username']) {
                continue;
            }
            echo "<img src='images/" . $row['username'] . "_thumb.jpg'> <br>";
            echo $row['name'] . '<br>';
            echo $row['status'] . '<br>';
            echo nicetime($row['updatetime']) . '<br>';

            if (!in_array($row['username'], $friends)) {
                echo "<a class='addButton' id='" . $row['username'] . "'>Add Friend</a>";
            }

            echo '<hr>';
        }
    }

    ?>

    <?php
}
include("includes/footer.php");
?>