'use strict';

module.exports = function(grunt) {
    grunt.loadNpmTasks('grunt-simple-mocha');
    grunt.loadNpmTasks('grunt-contrib-jshint');

    grunt.initConfig({
        pkg: grunt.file.readJSON('package.json'),

        simplemocha: {
            test:{
                src:['./listTests.js'],
                options:{
                    reporter: 'spec',
                    slow: 200,
                    timeout: 1000
                }
            }
        },

        jshint: {
            all: ['Gruntfile.js', './*.js'],
            options: {
                jshintrc: true,
                globals: {
                    console: true,
                    module: true
                }
            }
        },
    });
    grunt.registerTask('default', ['jshint', 'simplemocha:test']);
};
