<!--Root PHP start-->
<?php
    require('connection.php');
    session_start();

	$user_first_name = $_SESSION['user_first_name'];
	$user_last_name = $_SESSION['user_last_name'];
	$user_role = $_SESSION['user_role'];

	if(!empty($user_first_name) && !empty($user_last_name) && !empty($user_role)){
		$date = date('Y-m-d');

		if ($user_role == 'admin') {

?>
<!--Root PHP end-->

<!--PHP start-->
<?php
	if(isset($_GET['category_name'])){
		$category_name =  $_GET['category_name']; 
		$category_entry_date =  $_GET['category_entry_date'];

		$sql = "INSERT INTO product_category(category_name, category_entry_date) VALUES('$category_name', '$category_entry_date')";

		if ($conn->query($sql) == TRUE) {
			echo "New data inserted successfully!";
			header('location:category_lists.php');
		} else {
			echo "Error: " . $sql . "<br>" . $conn->error;
		}
	}
?><!--PHP end-->

<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
  <meta name="description" content="">
  <meta name="author" content="">
  <link href="img/logo/logo2.jpg" rel="icon">
  <title>Health Mart - Add Category</title>
  <link href="vendor/fontawesome-free/css/all.min.css" rel="stylesheet" type="text/css">
  <link href="vendor/bootstrap/css/bootstrap.min.css" rel="stylesheet" type="text/css">
  <link href="css/ruang-admin.min.css" rel="stylesheet">
  <!-- Select2 -->
  <link href="vendor/select2/dist/css/select2.min.css" rel="stylesheet" type="text/css">
  <!-- Bootstrap DatePicker -->  
  <link href="vendor/bootstrap-datepicker/css/bootstrap-datepicker.min.css" rel="stylesheet" >
	
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
    <?php include('sidebar.php') ?>
    <!-- Sidebar -->

    <div id="content-wrapper" class="d-flex flex-column">
      <div id="content">
        <!-- TopBar -->
        <?php include('topbar.php') ?>
        <!-- Topbar -->

        <!-- Container Fluid-->
        <div class="container-fluid" id="container-wrapper">
          <div class="d-sm-flex align-items-center justify-content-between mb-4">
            <h1 class="h3 mb-0 text-gray-800">Add Category</h1>
            <ol class="breadcrumb">
              <li class="breadcrumb-item"><a href="./">Home</a></li>
			  <li class="breadcrumb-item">Category</li>
              <li class="breadcrumb-item active" aria-current="page">Add Category</li>
            </ol>
          </div>
          
          <section class="content" style="font-size:initial;">

          <div class="row mb-3 content container-fluid card-body panel-default">

            <!--Add Category-->
			      <div class="col-lg-12">
              <div class="card mb-4">
                <div class="card-header py-3 d-flex flex-row align-items-center justify-content-between">
                  <h6 class="m-0 font-weight-bold text-primary">Insert Category</h6>
                </div>
				        <div class="panel card-body">
                  <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="GET">
                  <div class="row mb-3">
                  <div class="col-xl-6 col-lg-5 mb-4">
                  <div class=" form-group">
                  <div class="col-xl-6 col-lg-5 mb-4">
                    <label for="exampleInputCategory">Category Name</label></div>
                    <div class="col-xl-6 col-lg-5 mb-4">
                      <input type="text" name="category_name" class="form-control" id="exampleInputCategory" aria-describedby="emailHelp"
                        placeholder="Enter Category"></div>
                    </div>
                  </div>
                  
                  <div class="col-xl-6 col-lg-5 mb-4">
                    <div class=" form-group" id="simple-date1">
                    <div class="col-xl-6 col-lg-5 mb-4">
                      <label for="simpleDataInput">Category Entry Date</label></div>
                      <div class="col-xl-6 col-lg-5 mb-4">
                        <div class="input-group date">
                        <div class="input-group-prepend">
                          <span class="input-group-text"><i class="fas fa-calendar"></i></span>
                        </div>
                        <input type="text" name="category_entry_date" class="form-control" value="<?php echo $date ?>" id="simpleDataInput">
                      </div>
                      </div>
                  	</div>
                  </div>
                  </div>
                  
                  <div class="row mb-3">
                      <div class="col-xs-12 margin-top btn-group">
                        <button type="submit" class="btn btn-outline-primary float-right">Add</button>
                  </div></div>
                  </form>
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
          
        </section>

        </div>
        <!---Container Fluid-->
      </div>

      <!-- Footer -->
	  <?php include('footer.php') ?>
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
  <!-- Select2 -->
  <script src="vendor/select2/dist/js/select2.min.js"></script> 
  <!-- Bootstrap Datepicker -->
  <script src="vendor/bootstrap-datepicker/js/bootstrap-datepicker.min.js"></script>
  
  <!-- Javascript for this page -->
  <script>
    $(document).ready(function () {


      $('.select2-single').select2();

      // Select2 Single  with Placeholder
      $('.select2-single-placeholder').select2({
        placeholder: "Select a Province",
        allowClear: true
      });      

      // Select2 Multiple
      $('.select2-multiple').select2();

      // Bootstrap Date Picker
      $('#simple-date1 .input-group.date').datepicker({
        format: 'yyyy-mm-dd',        
        todayBtn: 'linked',
        todayHighlight: true,
        autoclose: true,        
      });

      $('#simple-date2 .input-group.date').datepicker({
        startView: 1,
        format: 'yyyy-mm-dd',        
        autoclose: true,     
        todayHighlight: true,   
        todayBtn: 'linked',
      });

      $('#simple-date3 .input-group.date').datepicker({
        startView: 2,
        format: 'yyyy-mm-dd',        
        autoclose: true,     
        todayHighlight: true,   
        todayBtn: 'linked',
      });

      $('#simple-date4 .input-daterange').datepicker({        
        format: 'yyyy-mm-dd',        
        autoclose: true,     
        todayHighlight: true,   
        todayBtn: 'linked',
      });    

      // TouchSpin

      $('#touchSpin1').TouchSpin({
        min: 0,
        max: 100,                
        boostat: 5,
        maxboostedstep: 10,        
        initval: 0
      });

      $('#touchSpin2').TouchSpin({
        min:0,
        max: 100,
        decimals: 2,
        step: 0.1,
        postfix: '%',
        initval: 0,
        boostat: 5,
        maxboostedstep: 10
      });

      $('#touchSpin3').TouchSpin({
        min: 0,
        max: 100,
        initval: 0,
        boostat: 5,
        maxboostedstep: 10,
        verticalbuttons: true,
      });

      $('#clockPicker1').clockpicker({
        donetext: 'Done'
      });

      $('#clockPicker2').clockpicker({
        autoclose: true
      });

      let input = $('#clockPicker3').clockpicker({
        autoclose: true,
        'default': 'now',
        placement: 'top',
        align: 'left',
      });

      $('#check-minutes').click(function(e){        
        e.stopPropagation();
        input.clockpicker('show').clockpicker('toggleView', 'minutes');
      });

    });
  </script>

</body>

</html>

<?php
		}else{
			header('location:index.php');
			die();
		}
	}else{
		header('location:login.php');
	}
?>