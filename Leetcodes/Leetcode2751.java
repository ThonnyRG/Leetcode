class Robot {
    int index;
    int health;
    boolean goingLeft;
  
    public Robot(int i, int health, char direction) {
      index = i;
      this.health = health;
      this.goingLeft = direction == 'L';
    }
  }
  
  TreeMap<Integer, Robot> treeMap = new TreeMap<>();
  Integer positionGoingLeft = 0;
  Integer positionGoingRight = 0;
  
  public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
    createTreeMap(positions, healths, directions);
    findFighters();
    return getResult();
  }
  
    void createTreeMap(int[] positions, int[] healths, String directions) {
      for (int i = 0; i < positions.length; i++) {
        Robot robot = new Robot(i + 1, healths[i], directions.charAt(i));
        treeMap.put(positions[i], robot);
      }
    }
  
    private void findFighters() {
      while (fightableRobotsExist()) {
        fight();
      }
    }
  
      private boolean fightableRobotsExist() {
        while (foundRobotGoingLeft()) {
          if (previousRobotGoesRight()) {
            return true;
          }
          positionGoingLeft++;
        }
        return false;
      }
  
        private boolean foundRobotGoingLeft() {
          positionGoingLeft = treeMap.ceilingKey(positionGoingLeft);
          while (positionGoingLeft != null) {
            Robot nextRobot = treeMap.get(positionGoingLeft);
            if (nextRobot.goingLeft) {
              return true;
            }
            positionGoingLeft = treeMap.higherKey(positionGoingLeft);
          }
          return false;
        }
  
        private boolean previousRobotGoesRight() {
          positionGoingRight = treeMap.lowerKey(positionGoingLeft);
          if (positionGoingRight == null) {
            return false;
          }
          Robot robotGoingRight = treeMap.get(positionGoingRight);
          return !robotGoingRight.goingLeft;
        }
  
      private void fight() {
        Robot robotGoingLeft = treeMap.get(positionGoingLeft);
        Robot robotGoingRight = treeMap.get(positionGoingRight);
        if (robotGoingRight.health == robotGoingLeft.health) {
          treeMap.remove(positionGoingLeft);
          treeMap.remove(positionGoingRight);
        } else if (robotGoingRight.health < robotGoingLeft.health) {
          treeMap.remove(positionGoingRight);
          robotGoingLeft.health--;
        } else {
          treeMap.remove(positionGoingLeft);
          robotGoingRight.health--;
        }
      }
  
  
    private List<Integer> getResult() {
      PriorityQueue<Robot> robotPriorityQueue = getPriorityQueueSortedByIndex();
      return getHealths(robotPriorityQueue);
    }
  
      private PriorityQueue<Robot> getPriorityQueueSortedByIndex() {
        PriorityQueue<Robot> priorityQueueSortedByOriginalIndex = new PriorityQueue<>
              (Comparator.comparingInt(a -> a.index));
        for (Map.Entry<Integer, Robot> entry : treeMap.entrySet()) {
          priorityQueueSortedByOriginalIndex.add(entry.getValue());
        }
        return priorityQueueSortedByOriginalIndex;
      }
    
      private List<Integer> getHealths(PriorityQueue<Robot> robotPriorityQueue) {
        List<Integer> results = new ArrayList<>();
        while (!robotPriorityQueue.isEmpty()) {
          Robot r = robotPriorityQueue.remove();
          results.add(r.health);
        }
        return results;
      }