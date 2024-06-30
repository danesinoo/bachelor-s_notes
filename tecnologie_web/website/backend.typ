= Backend

== Php

- ogni API ritorna una pagina HTML, che sia
    - get
    - post 
    - errore

- un form errato ritorna una pagina con il form già compilato e un messaggio di
  erorre

- un form corretto reindirizza se è il caso

- per ogni API c'è un file php che gestisce la richiesta, ad esempio:
  - `login.php`
  - `register.php`
  - `recipe.php`
  - `ingredient.php`

- connessione al database usa un Singleton del tipo:
  ```php
  <?php
  class Database {
      private static $instance = null;
      private $conn;
      private $host = 'localhost';
      private $user = 'username';
      private $pass = 'password';
  
      private function __construct() {
          Database::$conn = new mysqli($this->host, $this->user, $this->pass);
          // or something like that
  
          if (Database::$conn->connect_error) {
              die("Connection failed: " . Database::$conn->connect_error);
          }
      }
  
      public function getInstance() {
          if (Database::$instance == null) {
              Database::$instance = new Database();
          }
          return Database::$instance;
      }
  
      public query($sql_query, ...$params) {
          // check for sql injection
          // prepare statement
          // bind parameters
          // execute
          // return result
      }
  }
  ```

- ogni richiesta al database viene gestita mediante una funzione apposita per
  esempio:
  ```php
  <?php
  function get_recipe($id) {
      $sql = "SELECT * FROM recipes WHERE id = ?";
      $result = Database::getInstance()->query($sql, $id);
      return $result;
  }
  ```

- classe per la gestione delle sessioni/autenticazione/cookies/autorizzazione:
  ```php
  <?php
  class Session {
      public function start() {
          session_start();
      }
  
      public function set($key, $value) {
          $_SESSION[$key] = $value;
      }
  
      public function get($key) {
          return $_SESSION[$key];
      }
  
      public function destroy() {
          session_destroy();
      }

      public function is_logged_in() {
          return isset($_SESSION['user']);
      }

      public function login($user) {
          // check user credentials
          $_SESSION['user'] = $user;
      }

      public function logout() {
          unset($_SESSION['user']);
      }

      public function get_user() {
          return $_SESSION['user'];
      }

      ...
  }
  ```

- classe per la generazione delle pagine html:
  ```php
  <?php
  class Page {
      public function get_content($path) {
          $content = file_get_contents("layout/" . $path);
          $content = str_replace("{{ header }}", $this->get_header(), $content);
      }

      public function get_header() {
          return file_get_contents("layout/header.html");
      }

      // ...
  }
  ```
