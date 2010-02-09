<?php


/**
 *
 *
 *
 **/

/* SQL
  CREATE TABLE `players` (
    `id` UNSIGNED INT (5) not null auto_increment,
    `name` TEXT not null,
    `cash` FLOAT (20) not null default 1500,
    `invested` FLOAT (20) not null default 0,
    `loan` FLOAT (20) not null default 0,
    `credit` FLOAT (20) NOT NULL defaut 0,
    
    
  );
  
  CREATE TABLE `game` (
    `id` UNSIGNED INT (5) NOT NULL auto_increment,
    `name` TEXT not null,
    `loanrate` FLOAT (5) NOT NULL default 0.10,
    `creditrate` FLOAT (5) NOT NULL default 0.30,
    `investrate` FLOAT (5) NOT NULL default 0.05,
    `bankequity` FLOAT (10) NOT NULL default 15140,
    `bankout` FLOAT (10) NOT NULL default 0,
    
    
  );


*/


$dbuser = "monopoly";
$dbpass = "e2p7QZyDjU4bLTxD";
$dbhost = "localhost";
$dbname = "monopoly";


mysql_connect($dbhost, $dbuser, $dbpass);
mysql_select_db($dbname);



$loanrate; 


if(isset($_POST['update-user'])) {
    for($i=0; $i<$_POST['users']; $i++) {
        $userid = $_POST["userid$i"];
        $invested = ($_POST["userinvested$i"] > 0) ? $_POST['userprevinvested$i'] * $loanrate + $_POST["userinvested$i"] : ($_POST["userprevinvested$i"] - $_POST["userinvested$i"]) * $loanrate;
        mysql_query("UPDATE `players`
            SET
                `cash` = `cash` + ".$_POST["usercash$i"].",
                `invested` = $loanrate,
                `loan` = $loan,
                `credit` = $credit
            WHERE
                `id` = $userid
            LIMIT 1
        ");
    }
}