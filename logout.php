<?php
    session_start();
    echo "Successfully Logout!";
    session_destroy();
    header('location:login.php');
?>