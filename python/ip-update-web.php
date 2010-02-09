<?php

mysql_connect('localhost', 'computers', )

if(isset($_GET['id']) && isset($_GET['ip'])) {
    mysql_query("UPDATE `computers` SET `ip` = '".$_GET['ip']."' WHERE `id` = '".$_GET['id']."' LIMIT 1");
}
else {
    ?>
<html>
<head>
    <title>Computers</title>
    <style type="text/css">
        body {
            color: #FFFFFF;
            background-color: #000000;
        }
    </style>
<body>
    <code>
<?php
    $computers = mysql_query('SELECT * FROM `computers`');
    for($i=0;$i < mysql_num_rows($computers); $i++){
        echo mysql_result($computers,$i,"id")." : ".mysql_result($computers,$i,"ip")."<br />";   
    }
?>
    </code>
</body>
</html>

<?php
    
}

?>