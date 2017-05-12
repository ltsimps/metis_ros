#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
import actionlib
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal

def scan_callback(msg):
  global g_range_ahead
  g_range_ahead = min(msg.ranges)

g_range_ahead = .4 # anything to start
scan_sub = rospy.Subscriber('scan', LaserScan, scan_callback)
cmd_vel_pub = rospy.Publisher('cmd_vel', Twist, queue_size=1)
rospy.init_node('wander')
state_change_time = rospy.Time.now()
driving_forward = True
rate = rospy.Rate(10)
turnleft = False

move = 1.2
while not rospy.is_shutdown():
  if driving_forward:
    #if (g_range_ahead < 0.8 or rospy.Time.now() > state_change_time):
    if (g_range_ahead < 0.8):
    #if (rospy.Time.now() > state_change_time):
      driving_forward = False
      #state_change_time = rospy.Time.now() + rospy.Duration(5)
  else: # we're not driving_forward
       #twist.angular.z = -1
       #twist.linear.x = .4
       move = 1.2 
    #if rospy.Time.now() > state_change_time:
    #if rospy.Time.now() > state_change_time:
      #driving_forward = True # we're done spinning, time to go forward!
      #twist.angular.z = 1;
      #state_change_time = rospy.Time.now() + rospy.Duration(5)
  twist = Twist()
  if driving_forward:
    twist.linear.x = .4
    #twist.linear.y = 1
    #move = move - 0.4
  else:
    #twist.linear.y = -1
    twist.angular.z = .2
    driving_forward = True
  cmd_vel_pub.publish(twist)

  rate.sleep()

