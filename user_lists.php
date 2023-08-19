<!--Root PHP start-->
<?php
    require('connection.php');
    session_start();

	$user_first_name = $_SESSION['user_first_name'];
	$user_last_name = $_SESSION['user_last_name'];
	$user_role = $_SESSION['user_role'];

	if(!empty($user_first_name) && !empty($user_last_name) && !empty($user_role)){
?>
<!--Root PHP end-->

<!--PHP start-->
<?php
	$sql = "SELECT * FROM users";
	$query = $conn->query($sql);
?>
<!--PHP end-->

<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
  <meta name="description" content="">
  <meta name="author" content="">
  <link href="img/logo/logo2.jpg" rel="icon">
  <title>Health Mart - User List</title>
  <link href="vendor/fontawesome-free/css/all.min.css" rel="stylesheet" type="text/css">
  <link href="vendor/bootstrap/css/bootstrap.min.css" rel="stylesheet" type="text/css">
  <link href="css/ruang-admin.min.css" rel="stylesheet">
  <link href="vendor/datatables/dataTables.bootstrap4.min.css" rel="stylesheet">
  	
  <!-- CSS -->
	<link rel="stylesheet" href="css/min.css">
	<link rel="stylesheet" href="css/bootstrap.datetimepicker.css">
	<link rel="stylesheet" href="//cdn.datatables.net/1.10.7/css/jquery.dataTables.css">
	<link rel="stylesheet" href="//cdn.datatables.net/plug-ins/1.10.7/integration/bootstrap/3/dataTables.bootstrap.css">

    <!-- Ionicons -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/ionicons/2.0.1/css/ionicons.min.css">
  <!-- Theme style -->
  <link rel="stylesheet" href="css/AdminLTE.css">
  
</head>

<body id="page-top">
  <div id="wrapper">
    <!-- Sidebar -->
    <?php include'sidebar.php' ?>
    <!-- Sidebar -->

    <div id="content-wrapper" class="d-flex flex-column">
      <div id="content">
        <!-- TopBar -->
        <?php include'topbar.php' ?>
        <!-- Topbar -->

        <!-- Container Fluid-->
        <div class="container-fluid" id="container-wrapper">
          <div class="d-sm-flex align-items-center justify-content-between mb-4">
            <h1 class="h3 mb-0 text-gray-800">User List</h1>
            <ol class="breadcrumb">
              <li class="breadcrumb-item"><a href="./">Home</a></li>
			  <li class="breadcrumb-item">User</li>
              <li class="breadcrumb-item active" aria-current="page">User List</li>
            </ol>
          </div>

          <div class="row mb-3">
            <!--Data Tables-->
			<div class="col-lg-12">
              <div class="card mb-4">
                <div class="card-header py-3 d-flex flex-row align-items-center justify-content-between">
                  <h6 class="m-0 font-weight-bold text-primary">User Lists</h6>
                </div>
                <div class="table-responsive p-3">
                  <table class="table align-items-center table-flush table-hover text-dark" id="dataTableHover" style="text-align:initial;">
                    <thead class="thead-light">
                      <tr>
                        <th>User ID</th>
                        <th>First Name</th>
                        <th>Last Name</th>
                        <th>User Role</th>
                        <th>Email</th>
                        <th>Data Entry Date</th>
                        <th>Action</th>
                      </tr>
                    </thead>
                    <tfoot>
                      <tr>
                        <th>User ID</th>
                        <th>First Name</th>
                        <th>Last Name</th>
                        <th>User Role</th>
                        <th>Email</th>
                        <th>Data Entry Date</th>
                        <th>Action</th>
                      </tr>
                    </tfoot>
                    <tbody>
					  <?php
					  	$sl = 0;
                          while($data = mysqli_fetch_assoc($query)){
                            $user_id =  $data['user_id'];
                            $user_first_name02 =  $data['user_first_name'];
                            $user_last_name02 =  $data['user_last_name'];
                            $user_role =  $data['user_role'];
                            $user_email =  $data['user_email'];
                            $user_entry_date =  $data['user_entry_date'];
						  $sl++;
					   ?>
                      <tr>
                        <td><?php echo $sl?></td>
                        <td><?php echo $user_first_name02?></td>
                        <td><?php echo $user_last_name02?></td>
                        <?php if($data['user_role'] == "admin"){ ?>
                            <td><span class="badge badge-primary"><?php echo $user_role ?></span></td>
                        <?php }elseif ($data['user_role'] == "user"){ ?>
                            <td><span class="badge badge-info"><?php echo $user_role ?></span></td>
                        <?php } ?>
                        <td><?php echo $user_email?></td>
                        <td><?php echo $user_entry_date?></td>
						<?php if($user_first_name == $user_first_name02 && $user_last_name==$user_last_name02){?>
							<td>
								<a href="edit_user_data.php?id=<?php echo $user_id ?>" class="btn btn-success">
									<i class="fas fa-edit"></i>
								</a>
								<a href="delete_user_data.php?id=<?php echo $user_id ?>" class="btn btn-danger mx-3">
									<i class="fas fa-trash"></i>
								</a>
							</td>
						<?php }?>
                      </tr>
					  <?php } ?>
                    </tbody>
                  </table>
                </div>
              </div>
            </div>
          </div>
          <!--Row-->

          <!-- Modal Logout -->
          <div class="modal fade" id="logoutModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabelLogout"
            aria-hidden="true">
            <div class="modal-dialog" role="document">
              <div class="modal-content">
                <div class="modal-header">
                  <h5 class="modal-title" id="exampleModalLabelLogout">Ohh No!</h5>
                  <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                    <span aria-hidden="true">&times;</span>
                  </button>
                </div>
                <div class="modal-body">
                  <p>Are you sure you want to logout?</p>
                </div>
                <div class="modal-footer">
                  <button type="button" class="btn btn-outline-primary" data-dismiss="modal">Cancel</button>
                  <a href="login.html" class="btn btn-primary">Logout</a>
                </div>
              </div>
            </div>
          </div>

        </div>
        <!---Container Fluid-->
      </div>

      <!-- Footer -->
	  <?php include'footer.php' ?>
      <!-- Footer -->
	  
    </div>
  </div>

  <!-- Scroll to top -->
  <a class="scroll-to-top rounded" href="#page-top">
    <i class="fas fa-angle-up"></i>
  </a>

  <script src="vendor/jquery/jquery.min.js"></script>
  <script src="vendor/bootstrap/js/bootstrap.bundle.min.js"></script>
  <script src="vendor/jquery-easing/jquery.easing.min.js"></script>
  <script src="js/ruang-admin.min.js"></script>
  <script src="vendor/chart.js/Chart.min.js"></script>
  <script src="js/demo/chart-area-demo.js"></script>  
  <!-- Page level plugins -->
  <script src="vendor/datatables/jquery.dataTables.min.js"></script>
  <script src="vendor/datatables/dataTables.bootstrap4.min.js"></script>

  <!-- Page level custom scripts -->
  <script>
    $(document).ready(function () {
      $('#dataTable').DataTable(); // ID From dataTable 
      $('#dataTableHover').DataTable(); // ID From dataTable with Hover
    });
  </script>

</body>

</html>

<?php
	}else{
		header('location:login.php');
	}
?>