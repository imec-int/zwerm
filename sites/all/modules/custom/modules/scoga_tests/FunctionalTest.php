<?php
    /**
     * Camille Reynders, http://www.creynders.be
     * 07/08/12 - 14:50
     */
    class FunctionalTest extends DrupalWebTestCase{
        public function setUp( $modulename ) {
            $this->setup = TRUE;
        }
        /* *********************************************************/
        /* DO NOT REMOVE, even if empty (!!!)
        /* otherwise live data will get destroyed !
        /* *********************************************************/
        public function tearDown(){
            //DO NOT REMOVE, even if empty
        }

    }
